all: eggs

eggs: main.o init.o background.o display.o DrawBucket.o decrement.o mouse.o addToBasket.o ellipse.o sevensegment.o GameOver.o
	g++ main.o init.o background.o display.o DrawBucket.o decrement.o mouse.o addToBasket.o ellipse.o sevensegment.o GameOver.o -o eggs -lGL -lGLU -lglut -lm

main.o: main.cpp cg_project.h
	g++ -c main.cpp -lGL -lGLU -lglut -lm

init.o: init.cpp cg_project.h
	g++ -c init.cpp -lGL -lGLU -lglut -lm

background.o: background.cpp cg_project.h
	g++ -c background.cpp -lGL -lGLU -lglut -lm

display.o: display.cpp cg_project.h
	g++ -c display.cpp -lGL -lGLU -lglut -lm

DrawBucket.o: DrawBucket.cpp cg_project.h
	g++ -c DrawBucket.cpp -lGL -lGLU -lglut -lm

decrement.o: decrement.cpp cg_project.h
	g++ -c decrement.cpp -lGL -lGLU -lglut -lm

mouse.o: mouse.cpp cg_project.h
	g++ -c mouse.cpp -lGL -lGLU -lglut -lm

addToBasket.o: addToBasket.cpp cg_project.h
	g++ -c addToBasket.cpp -lGL -lGLU -lglut -lm

ellipse.o: ellipse.cpp cg_project.h
	g++ -c ellipse.cpp -lGL -lGLU -lglut -lm

GameOver.o: GameOver.cpp cg_project.h
	g++ -c GameOver.cpp -lGL -lGLU -lglut -lm

sevensegment.o: sevensegment.cpp cg_project.h
	g++ -c sevensegment.cpp -lGL -lGLU -lglut -lm

clean:
	rm -rf *o eggs

