#include <iostream>
#include <cmath>
#include <vector>
#include <math.h>
#include <thread>
#include <future>

using namespace std;


void sumsDivisible(int problem) //Project Euler problem 1
{
    int nSum = 0;
    for (int nCount = 1 ; nCount < problem ; nCount++)
    {

        if (nCount % 3 == 0 || nCount % 5 == 0)
            nSum += nCount;
    };
    cout << nSum << endl;
}

void fibonacciSums(int problem) //Project Euler problem 2
{
    int x = 0;
    int y = 1;
    int z;
    int sum = 0;

    do
    {
        z = x + y;
        x = y;
        y = z;
        if (y % 2 == 0)
            sum += y;
    } while (y <= problem);

    cout << sum << endl;

}

int primeChecker(long long problem)  //Checks if numbers are prime
{
    /*
    Check if number is prime
        Divide number by all numbers less than up to the number

    */

    for (long counter = 2 ; problem > counter ;)
    {
        if (problem == 2 || problem % counter !=0)
        {
            counter++;
            continue;
        } else
        {
            return 0;
        }

    }
    return problem;
}

void primeLister(long long topLim, vector<long long> &primeList) // Makes a list of primes
{
    for (long long possiblePrime = 5 ; possiblePrime <= topLim ;possiblePrime += 2)
    {
        bool isPrime = true;
        for (unsigned int counter = 0;counter < primeList.size();counter++)
        {
            if (possiblePrime % primeList.at(counter) == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            primeList.push_back(possiblePrime);

        if (topLim % possiblePrime == 0)
            topLim /= possiblePrime;

    }
}

void primeFactors(long long problem) //Project Euler problem 3
{
    cout << problem << endl;

    vector<long long> primes;
    primes.push_back(2);
    primes.push_back(3);

    vector<long long> primeList;
    primeLister(problem, primes);

    cout << primes.size() << endl;

    for (unsigned int counter = 0; counter < primes.size(); )
    {
        if (problem % primes.at(counter) == 0)
        {
            primeList.push_back(primes.at(counter));
            problem /= primes.at(counter);
        } else
        {
            counter++;
        }

    }

    for (int iii = 0 ; iii < primeList.size() ; iii++)
        cout << primeList.at(iii) << " " ;


}

bool isPalindrome(vector<char> problem) // Checks if numbers are palindrome numbers
{
    bool palindrome = true;       // If this is true, problem is palindrome

    int length = problem.size();  //Length of the problem
    //cout << length << endl;

    //This loop will check each element in problem and see if it is equal to the
    //one that is in spot length-iii
    for (int iii = 0 ; iii < length / 2; iii++)
        if (problem.at(iii) != problem.at(length - iii - 1)) //-1 because of how vectors .at() works
            palindrome = false;  // if the above statement is true, number is not palindrome

    return palindrome;
}

int vtoi(vector<char> vec, int beg, int ending) // vector to int
{
    int ret = 0;
    int mult = pow(10 , (ending-beg));

    for(int i = beg; i <= ending; i++)
    {
        ret += (vec[i] - '0') * mult;
        mult /= 10;
    }
    return ret;
}

int largestPalindromeProduct(int numOfCiphers) // Project Euler problem 4 unfinished
{
    vector<char> str(1, '1'); // Creates the vector that will be the starter. 10^x

    // This snippet adds as many 0's to str as is told in the calling of the function
    for (int counter = 0; counter < numOfCiphers - 1; counter++)
        str.push_back('0');

    int num = vtoi(str, 0, numOfCiphers - 1); // Convert str to int

    vector<int> number;
    long workingNum;
    int largestPalindrome = 0;

    for (long factor1 = pow(10.0, numOfCiphers) ; factor1 > num ; factor1--)
        for (long factor2 = pow(10.0, numOfCiphers) ; factor2 >= num ; factor2--)
        {
            vector<char> workingVect;
            workingNum = factor1 * factor2;

            if (workingNum == 0)
            {
                workingVect.push_back('0');
            }
            else
            {
                for ( ; workingNum; workingNum /= 10)
                    workingVect.push_back('0' + (workingNum % 10));
            }

            if (isPalindrome(workingVect))
            {
                // This little if/else block puts numbers from an int into a vector<char>
                // in reverse order. Not my solution.
                if (workingNum == 0)
                    number.push_back('0');
                else
                    for ( ; workingNum > 1; workingNum /= 10)
                        number.push_back('0' + (workingNum % 10));
                    break;
            }
            if (isPalindrome(workingVect))
                break;

        }

    for (int iii = 0 ; iii < number.size() ; iii++)
        cout << number.at(iii) << " ";
    return 0;
}

bool dividesByLessThan(int topLim, int number)
{
    bool isDivisible = true;
    for (int iii = 0 ; iii <= topLim ; iii++)
    {
        if ((topLim - iii) % number)
            isDivisible = false;
        cout << topLim << " " << iii << " " << number << " " << isDivisible << endl;
    }
    return isDivisible;
}

int smallestMultiple(int topLim) // Project Euler problem 5 unfinished
{
    int smallestNum = 2;
    for (int iii = 2 ; iii <= topLim ; )
    {
        if (dividesByLessThan(topLim, smallestNum))
            iii++;
        else
            smallestNum++;
        cout << smallestNum << " " << iii << endl;
    }

    // This for loop is just an error checker. It prints ERROR if number is
    // not evenly divisible by counter.
    for (int counter = 2 ; counter <= topLim ; counter++)
    {
        if (smallestNum % counter)
        {
            cout << "ERROR" << endl;
            break;
        }
    }
    cout << smallestNum << endl;
    return 0;
}

int main()
{
    smallestMultiple(3);

    return 0;
}
