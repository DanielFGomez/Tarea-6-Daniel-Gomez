burgers.png : generaGIF.py solBurgersU.dat solBurgersV.dat
	python generaGIF.py


solBurgersU.dat : burgers.x
	./burgers.x

solBurgersV.dat : burgers.x
	./burgers.x

burgers.x : burgers.c
	cc burgers.c -lm -o burgers.x
