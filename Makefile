TITLE=main

# \
!ifndef 0 # \
# nmake: \
CP=copy # \
MV=move # \
RM=del # \
TARGET=-I C:\INCLUDE -L C:\INCLUDE\SDL2 -l SDL2.lib -l SDL2main.lib -Xlinker /SUBSYSTEM:WINDOWS -o $(TITLE).exe # \
!else
# make:
CP=cp -f
MV=mv -f
RM=rm -f
TARGET=`sdl2-config --cflags --libs` -o $(TITLE)
# \
!endif

$(TITLE): $(TITLE).c
	$(CC) $(TITLE).c -Wall -std=c99 $(TARGET)
