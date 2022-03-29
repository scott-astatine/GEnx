##
# GForm-Vulkan pratice
# @version 0.1


CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

GEng: src/*.cpp include/*.hpp
	clang++ $(CFLAGS) -o build/GEng src/*.cpp $(LDFLAGS)

.PHONY: test clean

test: GEng
	./build/GEng

clean:
	rm -f GEng


# end
