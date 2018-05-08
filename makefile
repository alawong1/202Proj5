CXX = g++
CXXFLAGS = -Wall

proj5: driver.cpp StarWars.o Ship.o Imperial.o Rebel.o 
	$(CXX) $(CXXFLAGS) driver.cpp StarWars.o Ship.o Imperial.o Rebel.o -o proj5

StarWars.o: StarWars.cpp StarWars.h
	$(CXX) $(CXXFLAGS) -c StarWars.cpp

Ship.o: Ship.cpp Ship.h
	$(CXX) $(CXXFLAGS) -c Ship.cpp

Imperial.o: Imperial.cpp Imperial.h
	$(CXX) $(CXXFLAGS) -c Imperial.cpp

Rebel.o: Rebel.cpp Rebel.h
	$(CXX) $(CXXFLAGS) -c Rebel.cpp

clean:
	rm *.o

run:
	./proj5 proj5_imperial.txt proj5_rebel.txt

val:
	valgrind ./proj5 proj5_imperial.txt proj5_rebel.txt
