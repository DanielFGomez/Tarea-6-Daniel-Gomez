#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define USAGE "./burgers.x"
 
void copyT(double *origen, double *destino,int T);
double *reservar(int puntos);
void resolver(double *u, double *v);
void guardar(double *x,char *filename);
void iniciar(double *u,double*v);
 
int nx;
int ny;
int nt;

double dx;
double dy;
double sigma;
double nu;
double dt;


 
main(){
 
  nx = 41;
  ny = 41;
  nt = 12;
  dx = 2.0/(nx-1);
  dy = 2.0/(ny-1);
  sigma = .0009;
  nu = 0.01;
  dt = sigma*dx*dy/nu;
 
  double *u;
  double *v;
  double *un;
  double *uv;

  u = reservar(nx*ny*nt);
  v = reservar(nx*ny*nt);
  iniciar(u,v);
  printf("error en resolver");
  resolver(u,v);
  printf("error en guardar");

  guardar(u,"solBurgersU.dat");
  guardar(v,"solBurgersV.dat");
}
 

 
double *reservar(int puntos){
  double *array=malloc(puntos*sizeof(double));
  int i;
    for(i=0;i<puntos;i++){
    array[i]=1.0;
      }
  return array;
}

void iniciar(double *u, double *v){
  int x;
  int y;
  for(x=11;x<=21;x++){
    for (y=11;y<=21;y++){
      u[x+nx*y]=2;
      v[x+nx*y]=2;
      /*prueba */     
      u[x]=3;
    }
  }
}
 
void resolver(double *u, double *v){

  double *un;
  double *vn; 
  un = reservar(nx*ny);
  vn = reservar(nx*ny);

  int t;
  int x;
  int y;

  for (t=0;t<nt-1;t++){
    copyT(u,un,t);
    copyT(v,vn,t);
    for(y=1;y<ny-1;y++){
      for (x=1;x<nx-1;x++){
	  u[(t+1)*nx*ny+y*nx+x]=un[x+y*nx]
	    -dt/dx*un[x+y*nx]*(un[x+y*nx]-un[x-1+y*nx])
	    -dt/dy*vn[x+y*nx]*(un[x+y*nx]-un[x+(y-1)*nx])
	    +nu*dt/(dx*dx)*(un[x+1+y*nx]-2*un[x+y*nx]+un[x-1+y*nx])
	    +nu*dt/(dy*dy)*(un[x+(y+1)*nx]-2*un[x+y*nx]+un[x+(y-1)*nx]);

	  v[(t+1)*nx*ny+y*nx+x]=vn[x+y*nx]
	    -dt/dx*un[x+y*nx]*(vn[x+y*nx]-vn[x-1+y*nx])
	    -dt/dy*vn[x+y*nx]*(vn[x+y*nx]-vn[x+(y-1)*nx])
	    +nu*dt/(dx*dx)*(vn[x+1+y*nx]-2*vn[x+y*nx]+vn[x-1+y*nx])
	    +nu*dt/(dy*dy)*(vn[x+(y+1)*nx]-2*vn[x+y*nx]+vn[x+(y-1)*nx]);
	}
      }
    /*
    for (x=0;x<nx;x++){
      u[(t+1)*nx*ny+x]=1;
      u[(t+1)*nx*ny+x+(nx*(ny-1))]=1;
      v[(t+1)*nx*ny+x]=1;
      v[(t+1)*nx*ny+x+(nx*(ny-1))]=1;
    }
    for (y=0;y<ny;y++){
      u[(t+1)*nx*ny+y*nx]=1;
      u[(t+1)*nx*ny+nx-1+y*nx]=1;
      v[(t+1)*nx*ny+y*nx]=1;
      v[(t+1)*nx*ny+nx-1+y*nx]=1;
    }

    */
   }
    
}


 
void guardar(double *u,char *filename){
  FILE *in;
  int t;
  int x;
  int y;
 
 for(t=0; t<nt;t++){

    char str[80];
    sprintf(str,"%s%d",filename,t);
    in = fopen(str,"w");
    for(y=0;y<ny;y++){
      for(x=0;x<nx;x++){
	fprintf(in,"%f, ",u[t*nx*ny+y*nx+x]);
      }
    fprintf(in,"\n");
    }
  fclose(in);
 }
}
void copyT(double *origen, double *destino, int T){
  int i;
  for(i=0;i<=nx*ny;i++){
    destino[i] = origen[T*nx*ny+i];
  }
}
