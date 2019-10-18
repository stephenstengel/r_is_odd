#Stephen Stengel <stephen.stengel@cwu.edu>
#A makefile for r_is_odd()

r_is_odd: r_is_odd.c
	gcc -Wall -o r_is_odd r_is_odd.c

.PHONY: clean
clean:
	rm r_is_odd

.PHONY: backup
backup:
	ssh-backup-pi | lolcat
