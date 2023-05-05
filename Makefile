# Compiler settings
CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c99

# Directory structure
SRCDIR = ./src
INCDIR = ./src/include
BUILDDIR = ./build
LIBDIR = ./lib
INSTALLDIR = /usr/local/lib

# Library information
LIBNAME = gvec
LIBRARY = $(LIBDIR)/lib$(LIBNAME).a
SOURCES = $(wildcard $(SRCDIR)/*.c)
HEADERS = $(wildcard $(INCDIR)/*.h)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SOURCES))

# Build rules
all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
	ar rcs $@ $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCDIR)

install: $(LIBRARY)
	install -m 644 $(LIBRARY) $(INSTALLDIR)
    
pack:
	zip -r gvec.zip $(SRCDIR) $(INCDIR) Makefile

clean:
	rm -f $(LIBRARY) $(OBJECTS)
