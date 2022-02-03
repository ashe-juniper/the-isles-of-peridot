CC?=clang
CLANG?=clang
LD?=clang

TITLE_NAME=The Isles of Peridot

ASSETS_DIR=assets
MUSIC_DIR=$(ASSETS_DIR)/music
SOUNDS_DIR=$(ASSETS_DIR)/sounds
SPRITES_DIR=$(ASSETS_DIR)/sprites

LOCAL_DIR=$(HOME)/.the-isles-of-peridot
LOCAL_ASSETS_DIR=$(LOCAL_DIR)/assets
LOCAL_MUSIC_DIR=$(LOCAL_ASSETS_DIR)/music
LOCAL_SOUNDS_DIR=$(LOCAL_ASSETS_DIR)/sounds
LOCAL_SPRITES_DIR=$(LOCAL_ASSETS_DIR)/sprites

CLIENT_EXECUTABLE_NAME=the-isles-of-peridot
CLIENT_EXECUTABLE_PATH=$(CLIENT_EXECUTABLE_NAME)
CLIENT_DARWIN_APP_DIR=$(TITLE_NAME).app

INFO_PLIST=Info.plist
INFO_PLIST_PATH=$(CLIENT_DARWIN_APP_DIR)/Contents/$(INFO_PLIST)

CC_CLIENT_FLAGS=
CC_SERVER_FLAGS=

LD_CLIENT_FLAGS=
LD_SERVER_FLAGS=

DARWIN_CLIENT_EXECUTABLE_NAME=the_isles_of_peridot
DARWIN_CLIENT_EXECUTABLE_PATH=$(DARWIN_CLIENT_EXECUTABLE_NAME)
DARWIN_LD_FLAGS=-framework IOKit -framework Cocoa -framework OpenGL -L../lib/darwin/amd64 `pkg-config --libs --cflags raylib`

OBJECTS=game_window.o api.o main.o

all: client

client: $(OBJECTS)
	$(LD) $(LD_CLIENT_FLAGS) $^ -o $(CLIENT_EXECUTABLE_PATH)

darwin_client: $(OBJECTS)
	$(CLANG) $(LD_CLIENT_FLAGS) $(DARWIN_LD_FLAGS) $^ -o $(DARWIN_CLIENT_EXECUTABLE_PATH)

darwin_app: darwin_client
	mkdir -p "$(CLIENT_DARWIN_APP_DIR)"
	mkdir -p "$(CLIENT_DARWIN_APP_DIR)/Contents/MacOS"
	mkdir -p "$(CLIENT_DARWIN_APP_DIR)/Contents/Resources"

	cp $(DARWIN_CLIENT_EXECUTABLE_PATH) "$(CLIENT_DARWIN_APP_DIR)/Contents/MacOS"
	cp $(INFO_PLIST) "$(INFO_PLIST_PATH)"

install_darwin:
	mkdir -p $(LOCAL_DIR)
	cp -r $(ASSETS_DIR) $(LOCAL_ASSETS_DIR)

%.o: %.c
	$(CC) $(CC_CLIENT_FLAGS) -c $< -o $@
