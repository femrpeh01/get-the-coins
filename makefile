
all:
	g++ src/*.cpp -o game -I vendor/SFML/include -L vendor/SFML/lib -lsfml-system -lsfml-graphics -lsfml-window && game