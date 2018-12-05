Performance test of ORC's RLEV2Util functions
============================================

test.cc measures the performance of two different implementations of functions in ORC C++ library's RLEV2Util.hh.

It can be used to verify the code changes made in ORC-444 and ORC-445 (https://github.com/apache/orc/pull/346).

The "original" implementation uses if-else branches to compute bit widths, while the "new" implementation uses
arrays as look up tables.

For each implementation of a function, the test calls the function in a loop with all possible input values,
and measures the overall wallclock time. It also computes and reports the sum of the returned values to ensure both
implementations produce the same results.

To make it a standalone test, the related files (RLEV2Util.cc and RLEV2Util.hh) are copied from orc codebase and slightly modified.

To compile the test, type:

````
g++ test.cc RLEV2Util.cc -I . -O3 -o test
````

To run the test, type: 

````    
./test
````

The output looks like this on my MacBook:

````
decodeBitWidth(): 
original implementation:
 sum:  345294336
 time: 2.11403e+06 micro-seconds
new implementation:
 sum:  345294336
 time: 1.44804e+06 micro-seconds

getClosestFixedBits():
original implementation:
 sum:  4090641581
 time: 3.34408e+06 micro-seconds
new implementation:
 sum:  4090641581
 time: 2.50829e+06 micro-seconds

getClosestAlignedFixedBits():
original implementation:
 sum:  2432037948
 time: 4.33361e+06 micro-seconds
new implementation:
 sum:  2432037948
 time: 2.50046e+06 micro-seconds

encodeBitWidth():
original implementation:
 sum:  865711526
 time: 4.57794e+06 micro-seconds
new implementation:
 sum:  865711526
 time: 2.72641e+06 micro-seconds
````

