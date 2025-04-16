.PHONY: all build run test

all: build run

build:
	echo "Generating Ninja..."
	@gn gen out

	echo "Building Project..."
	@ninja -C out

run:
	@./out/main
