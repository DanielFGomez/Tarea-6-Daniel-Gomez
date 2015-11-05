from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
import matplotlib.pyplot as plt
import numpy as np

nx=41
ny=41
dataU=np.genfromtxt("solBurgersU.dat",delimiter=",")
dataV=np.genfromtxt("solBurgersV.dat",delimiter=",")
dataU=np.delete(dataU,-1,1)
dataV=np.delete(dataV,-1,1)
x=np.linspace(0,2,nx)
y=np.linspace(0,2,nx)
X,Y=np.meshgrid(x,y)
contador=0
print type(dataU)
for u,v in zip(dataU,dataV):
    a=u.reshape(nx,ny)
    fig=plt.figure(plt.figsize(10,10))
    ax=fig.gca(projection='3d')
    wire1=ax.plot_wireframe(X,Y,a[:], cmap=cm.coolwarm)
    plt.savefig("iteracion" + str(contador) + ".png")
    contador+=1

