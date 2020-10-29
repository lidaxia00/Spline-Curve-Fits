CC = gcc


CFLASS = -Wall -O -g 

TARGET = tcspl

.PHONY: all run clean

SOURCES = $(wildcard *.c *.cpp)
OBJS = $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCES)))

all: $(OBJS)
	@echo building...
	@cd build && $(CC) $(OBJS) -o $(TARGET) -lm
	@echo done！
	@#chmod a+x $(TARGET)
	
%.o:%.c
	@mkdir -p build 
	$(CC) $(CFLASS) -c $< -o build/$@
		
run: 
	@build/$(TARGET)

clean:
	rm -rf build
	@#rm -rf *.o rbftest