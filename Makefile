all:
	gcc main.c obfuscator.c helpers.c -o obfuscator

run:
	./obfuscator
	cat output.mc
