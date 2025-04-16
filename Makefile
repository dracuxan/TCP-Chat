.PHONY: build clean

build:
	@echo "Generating Ninja..."
	@gn gen out

	@echo "Building Project..."
	@ninja -C out

clean:
	@echo "Cleaning build artifacts..."
	@rm -rf out
