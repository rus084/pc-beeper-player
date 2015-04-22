# pc-beeper-player
play wav music on pc beeper at linux pc
©2015 Sidin Dmitriy

first release :
for play music you must make C array from .wav file with 8bit sample quality . then you must change CYCLE_WAIT for normal play speed and compile it . run only with root rights .
todo : auto calculating of CYCLE_WAIT
todo : open files from file system (./speaker "file") or STDIN ("cat "file" | ./speaker")