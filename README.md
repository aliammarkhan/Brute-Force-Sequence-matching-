# Brute-Force-Sequence-matching-
Brute force sequence matching in C++

## About problem
In bioinformatics, a sequence alignment is a way of arranging the sequences of DNA, RNA, or
protein to identify regions of similarity that may be a consequence of functional, structural, or
evolutionary relationships between the sequences. In this problem there are two sequences of
variable length given to you, you can keep them in simple DynamicSafeArray. The brute force
sequence matching algorithm finds the maximum sequence of match from the two given sequence.
Obviously this maximum match would not be larger than the smaller sequence. The sequence
matching may disallow characters in either sequence that already appears in the earlier match, but
missing from the next possible match. For example, consider the sequence S1 and S2

S1: ACTTGTTACTGTTACCT
S2: ACTGTACTGTACT
Matched: ACT*GT*ACTGT*AC*T

Here the matched sequence is greater than the length of the smallest sequence as we are
disallowing match of a character that earlier matched. In the above example there are four such
instances hence the match sequence is of length |s2| + 4,

Input
The input file contains a sequence S1 and S2 in the first two lines. Every sequence is between 1
to 80 characters long.

Output
The output file contains the matched sequence between the two given sequences. 

```bash
Input file
ACGTCCTTCATT
GTCTCATG 

Output file
GTC*T*CAT* 


```
