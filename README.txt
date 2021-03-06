﻿
“Develop a C library for the integers of arbitrary length (intal)”



Advanced problem solving skills for software engineer

Name:Vikas Kalagi
SRN :PES1201701654
SEC :B


Submitted by:

INTRODUCTION:


a)what is intal?
        
Ans:-intal refers to INTEGER TO ARBITRARY LENGTH


We Design a C library of integers of arbitrary length.It has functions that have mathematical operations on the Intal.According to the problem statement,the integers could be positive or zero with no leading zeros in it.


b)How is it different from an integer in general and integer data types supported by C?


Ans:- In C, we cannot do mathematical operations on integers having 1000 digits since we don't have a datatype to store such large integers having 1000 digits.Hence if we need to do mathematical operations on such large integers of 1000 digits we can do using this intal_library.Hence since intal_librarary supports the mathematical operations of two large integers which cannot be stored as the integer datatypes in C and small integers .


c)Applications of intal


Ans:- i)we can do mathematical operations on integers having upto 1000 digits.
        ii)Assume there’s an application written in C language there may be conditions where u need to perform mathematical operations on integers that cannot be stored using c datatypes.At this particular time,we can use the intal_library to do all mathematical operations easily.


The following functions are implemented on the Intals:
i)add two integers of arbitrary length
ii)subtract two integers of arbitrary length
iii)multiply two integers of arbitrary length
iv)mod of two integers of arbitrary length
v)compare two integers of arbitrary length
vi)power of a integer of arbitrary length and integer of type unsigned int
vi)gcd of integers of arbitrary length
vii)nth fibonacci number(where n is unsigned int)
viii)binomial coefficient of two integers of type unsigned int
ix)minimum of integers of the array and each  integer of arbitrary integer.
x)maximum of integers of the array and each integer of arbitrary integer.
xi)search for the integer in the array and return the index
xii)factorial of the integer of type unsigned int
xiii)sort the array
xiv)binary search in a sorted array
xv)coin row problem(DP)


My approach in implementing the functionalities of intal.


i)add two integers of arbitrary length
Brute force approach:Addition of two numbers done from right to left taking carry into the account and storing the modulo of the result and storing it in the array and atlast reversing the character array and returning the array.


ii)Subtract two integers of arbitrary length
Brute force approach:First we compare the two integers(intal_compare function) and the greater one will be send as the minuend and lesser one will be send as the subtrahend .subtraction two integers done from right to left.if the Minuend is less than the subtrahend then we add 10 to the minuend and subtract it with the subtrahend and subtract the next digit with -1 from right to left and the same process repeats.At the end if the minuend is left with some digits we directly add them to the result array.And in the end we remove the leading zeros after reversing the array and return that character array.


iii)compare two integers of arbitrary length
Brute force approach:Since it is mentioned in the document that there won't any leading zeros, we first compare with the length of the two integers and return -1 if the integer has the largest length else return 1 and if the length of two integers are same and then we compare the each number of the two integers from left to right and return 1 if integer 1 has the larger than the integer 2 else if integer 1 is less than integer 2 we return -1 and if two integers are exactly same we return 0.


iv)multiply two integers of arbitrary length
Brute force approach:we first find the integer with smallest length and send it as the second argument to the function i defined ang i take each number from the second integer and multiply it with the each number in the integer 1 and on each iteration i increment a variable coin which tells me the number of zeroes to be added at the end and add that the previously computed product each time (intal_add function) and finally return the sum of all through a character array.


v)mod of two integers of arbitrary length
Binary Search Approach:In this approach i will divide the result=intal1 by 2 and check if the (result * intal2) is less than intal and if it is less than intal1 ,we find the difference of (intal11)-(result*intal2)(using intal_subtract function) and check if the result of subtraction is less than intal2 and if it is less than intal2 we return that result of subtraction.else we check in the right o else we check in the left.and repeat the process.


vi)power of a integer of arbitrary length and integer of type unsigned int
BruteForceApproach: In this approach,we multiply the intal1 with intal1 n times and return the final answer.


vii)gcd of integers of arbitrary length
Euclidean Algorithm: 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}
In order to find the mod we use intal_mod function.


viii)nth fibonacci number(where n is unsigned int)
We take three arrays a,b,c and we find initialize of the a=0,b=1 and we do n-2 loops and do c=a+b;a=b;b=c; and atlast return c.


ix)binomial coefficient of two integers of type unsigned int(nck)
We take the character array and of length k and initialize the array with 0 and assign the first character array with 1 and we run two for loops one form 1to n and other from min(i,k) to zero and store the addition of c[j]+c[j-1] and at final we return c[k].

x)minimum of integers of the array and each  integer of arbitrary integer.
I iterate through the array and at first i will be maintaining a character array min and compare each character array with the all the other character array and find the min and return the index of that character array.


x)maximum of integers of the array and each  integer of arbitrary integer.
I iterate through the array and at first i will be maintaining a character array max and compare each character array with the all the other character array and find the max and return the index of that character array.


xi)search in an array(return index of the first element)
Linear Search: we iterate through the array and check for the key given and if found we will return the index of that character array in the array and if not found we will return -1


xii)factorial of a number 
for (i=1->n)
mul=mul*(i)
Return mul


xiii)sort the array
Merge Sort to the sort the array


xiv)binary Search :
Search a sorted array by repeatedly dividing the search interval in half. Begin with an interval covering the whole array. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half. Otherwise narrow it to the upper half. Repeatedly check until the value is found or the interval is empty.


xv)coin_row problem:
In this problem we will find the max(dp[i-2]+a[i],dp[i-1]) and store in the array and return the dp[n-1]


dp[i]=max(dp[i-2]+arr[i],dp[i-1])

Future work 
   1. Any more functionalities you think that can be included in the intal library?
We may also add a Division of two integers into the library.
   2. If you had no restrictions, how would you implement a library to handle integers of arbitrary length?
i)we can do it for integers containing more than 1000 digits
ii)we can do these operation for integers containing the leading Zeros
iii)difference of two integers can be negative also
iv)we can do these operation for negative integers also.
