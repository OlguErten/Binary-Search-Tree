CFLAGs=-w -g

all:
	gcc -w -g main.c Node.c Stack.c -o Playlist_Creator.a

clean:
	rm -f Playlist_Creator.a