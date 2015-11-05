K := 1
ALFA := 0
trayectoria.pdf : graficarTrayectoria.py trayectoria_E_alpha.dat
	python graficarTrayectoria.py
	firefox trayectoria.pdf

trayectoria_E_alpha.dat : particle_in_field.x
	./particle_in_field.x $(K) $(ALFA)
particle_in_field.x : particle_in_field.c
	cc particle_in_field.c -lm -o particle_in_field.x
