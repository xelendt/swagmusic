CXX = g++
CXXFLAGS = -g \
			-framework OpenGL \
			-framework GLUT \
			-Wno-deprecated \
			#`pkg-config --cflags --libs opencv` \
			-lpng
TARGETS = main.cpp
EXEC = dancer

all: 
	$(CXX) $(TARGETS) -o $(EXEC) $(CXXFLAGS)

run: 
	make; ./$(EXEC)

clean:
	rm $(EXEC)
