CFLAGS = -Wall -std=c99 -g -Werror -O3

SRCS = h.c
OBJS = $(SRCS:.c=.o)
BIN = h


all: $(BIN)

$(BIN): $(OBJS)
	$(CC) -o $(BIN) $(OBJS)

clean:
	$(RM) $(BIN) $(OBJS)

