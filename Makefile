build:
	@go build -o bin/fs

test:
	@go test ./... -v

run:
	@./bin/fs
