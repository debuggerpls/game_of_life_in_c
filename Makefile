gameoflife: conditions.o expanded_draw.o gameoflife.o simple_draw.o
	gcc conditions.o expanded_draw.o gameoflife.o simple_draw.o -o gameoflife

conditions.o: conditions.c conditions.h
	gcc conditions.c -c

expanded_draw.o: expanded_draw.c expanded_draw.h
	gcc expanded_draw.c -c

gameoflife.o: gameoflife.c
	gcc gameoflife.c -c

simple_draw.o: simple_draw.c simple_draw.h
	gcc simple_draw.c -c

clean:
	rm *.o gameoflife
