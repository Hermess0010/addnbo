TARGET=addnbo
CXXFLAGS=-g

all: $(TARGET)

$(TARGET): addnbo.cpp
	$(LINK.cpp) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f $(TARGET)
	rm -f *.o
