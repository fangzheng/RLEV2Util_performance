Performance test of ORC's RLEV2Util functions
============================================

test.cc measures the performance of two different implementations of functions in ORC C++ library's RLEV2Util.hh.
It is used to verify the code changes made in ORC-444 and ORC-445 (https://github.com/apache/orc/pull/346).

The "original" implementation uses if-else branches to compute bit widths, while the "new" implementation uses
arrays as look up tables.

For each implementation of a function, the test calls the function in a loop with all possible input values,
and measures the overall wallclock time. It also computes and reports the sum of the returned values to ensure both
implementations produce the same results.

To make it a standalone test, the related files (RLEV2Util.cc and RLEV2Util.hh) are copied from orc codebase and slightly modified.

To compile the test, type:
    g++ test.cc RLEV2Util.cc -I . -O3 -O test

To run the test, type: 
    ./test

