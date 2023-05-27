This is a set of solutions the "Maximum Subarray" problem on Leetcode.

Given a vector of numbers with a length between 1..100000
And all integer in the set between -10000..10000

Find the "sub array" with the largest sum

https://leetcode.com/problems/maximum-subarray/

solution.cpp - this is the accepted solution and O(n) algorithm. It creates a summation array then looks for the biggest delta between local mimimums and local maximums.

dynamicSolutionNoCache.cpp - this solution passes most test cases, but fails with a time limit exceeded on some of the larger input set. It uses a classic dynamic programming solution.

dynamicSolutionWithCache.cpp - this solution passes more test cases than the previous solution, but still fail with a time limit exceeded on some of the larger input set. It extends the previous solution with a cache of previous recursion results.

