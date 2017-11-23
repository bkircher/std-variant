CC=/usr/local/opt/llvm/bin/clang++

CFLAGS=-std=c++17 -stdlib=libc++ -O0 -g \
	-Weverything -Wno-c++98-compat \
	-nostdinc++ -isystem /usr/local/opt/llvm/include/c++/v1 \
	-I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/ \
	-L/usr/local/opt/llvm/lib -Wl,-rpath,/usr/local/opt/llvm/lib \

EXAMPLES=example1 \

all: $(EXAMPLES)

$(EXAMPLES):%:%.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f example? && rm -rf example?.dSYM/
