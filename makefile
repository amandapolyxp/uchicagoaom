FLAGS  = -Wall -g -pthread 
CC     = gcc
PROG   = makeListsO
OBJS   = model_lists.o

all:	${PROG}

clean:
	rm ${OBJS} ${PROG} *~

${PROG}:	${OBJS}
	${CC} ${FLAGS} ${OBJS} -o $@

.c.o:
	${CC} ${FLAGS} $< -c

##########################


model_lists.o: model_lists.h model_lists.c

corridas: project.o
