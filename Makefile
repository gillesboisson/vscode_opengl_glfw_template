# SRCS specifies which files to compile as part of the project

SRC_PATH = src
OBJ_PATH = obj
BIN_PATH = bin

APP_NAME = main

SRCS = $(SRC_PATH)/*.cpp
OBJS = $(OBJ_PATH)/*.o
APP_PATH = $(BIN_PATH)/$(APP_NAME)

SRC= $(wildcard $(SRCS))
OBJ= $(subst $(SRC_PATH),$(OBJ_PATH),$(SRC:.cpp=.o))
#//OBJ= $(OBJS:.o)

# CC specifies which compiler we're using
CC = g++
RM = rm

# INCLUDE_PATHS specifies the additional include paths we'll need
INCLUDE_PATHS = -I/usr/local/include -I/opt/X11/include

# LIBRARY_PATHS specifies the additional library paths we'll need
LIBRARY_PATHS = -L/usr/local/lib -I/opt/X11/lib

# COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

ifeq ($(DEBUG),yes)
	COMPILER_FLAGS += -g
endif

# LINKER_FLAGS specifies the libraries we're linking against
# Cocoa, IOKit, and CoreVideo are needed for static GLFW3.
LINKER_FLAGS = -lglfw3  -lGLEW -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo


# APP_NAME specifies the name of our exectuable

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	$(CC) -o $@ -c $< $(COMPILER_FLAGS) 

#This is the target that compiles our executable
$(APP_NAME) : $(OBJ)
	$(CC) $(OBJ) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(APP_PATH)
	
# clean all sources
clean:
	$(RM) -rf $(OBJS)
	$(RM) -rf $(SRC_PATH)/*o
	$(RM) -rf $(APP_PATH)