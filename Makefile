.PHONY: build


build:
	echo "Generating Ninja..."
	@gn gen out

	echo "Building Project..."
	@ninja -C out
