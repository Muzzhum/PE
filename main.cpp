#include <iostream>
#include <cmath>
#include <vector>
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

void primeLister(long long topLim, vector<unsigned long long> &primeList) // Makes a list of primes
{
    for (unsigned long long possiblePrime = 3 ; possiblePrime <= topLim ; possiblePrime += 2)
    {
        bool isPrime = true;
        for (unsigned long long counter = 0 ; counter < primeList.size() ; counter++)
        {
            if (possiblePrime % primeList.at(counter) == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            primeList.push_back(possiblePrime);
    }
}

void primeFactors(long long problem) //Project Euler problem 3
{
    vector<unsigned long long> primes;
    primes.push_back(2);
    primes.push_back(3);

    vector<unsigned long long> primeList;
    primeLister(problem, primes);

    for (unsigned int counter = 0 ; counter < primes.size() ; )
    {
        if (problem % primes.at(counter) == 0)
        {
            primeList.push_back(primes.at(counter));
            problem /= primes.at(counter);
        } else
            counter++;
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

bool dividesByLessThan(int topLim, int number) // Divides a number by all numbers smaller than it
{
    bool isDivisible = true;
    for (int iii = 0 ; iii < topLim ; iii++)
        if (number % (topLim - iii))
        {
            isDivisible = false;
            return isDivisible;
        }
    return isDivisible;
}

int smallestMultiple(int topLim) // Project Euler problem 5
{
    int smallestNum = 2;
    for (int iii = 2 ; iii <= topLim ; )
    {
        if (dividesByLessThan(topLim, smallestNum))
            iii++;
        else
            smallestNum++;
    }

    // This for loop is just an error checker. It prints ERROR if number is
    // not evenly divisible by counter.
    for (int counter = 2 ; counter <= topLim ; counter++)
    {
        if (smallestNum % counter)
        {
            cout << "ERROR, Number is not divisible by all numbers smaller!" << endl;
            break;
        }
    }
    return smallestNum;
}

int sumSquareDifference(int topLim) // Project Euler problem 6
{
    int squareSum = 0;
    for (int iii = 1 ; iii <= topLim ; iii++)
        squareSum += pow(iii, 2);

    double sumSquare = 0;
    for (double jjj = 1 ; jjj <= topLim ; jjj++)
        sumSquare += jjj;
    sumSquare = pow(sumSquare, 2.0);

    cout << sumSquare << " " << squareSum << endl;
    int difference = sumSquare - squareSum;
    return difference;
}

int specialPythagoreanTriplet(int sum) // Project Euler problem 9
{
    /*
    A pythagorean triplet looks like this: a < b < c
    where a^2 + b^2 = c^2
    There is exactly one pythagorean triplet where a+b+c = 1000.
    Find product abc.
    */

    float answerA, answerB, answerC = 0.0;

    for (float possibleB = 4.0 ; possibleB < 500 ; possibleB++)
        for (float possibleA = 3.0; possibleA <= possibleB ; possibleA++)
        {
            float possibleC = sqrt(pow(possibleA, 2) + pow(possibleB, 2));

            if (possibleA + possibleB + possibleC == 1000)
            {
                answerA = possibleA;
                answerB = possibleB;
                answerC = possibleC;
            }
        }


    int answer = answerA * answerB * answerC;
    return answer;
}

long long summationOfPrimes(long long topLim) // Project Euler problem 10 unfinished
{
    vector<unsigned long long> primes(1, 2);
    primeLister(topLim, primes);

    long long sum = 0;
    for (long iii = 0 ; iii < primes.size() ; iii++)
        sum += primes.at(iii);
    return sum;
}

long collatzMachine(long num)
{
    /*
    COLLATZ MACHINE
    input: num
    if num % 2 == 0
        num =/2
        sequenceLength++
    else
        num *= 3
        num ++
        sequenceLength++
    */
    long length = 0;
    while (num != 1)
    {
        if (num % 2 == 0)
        {
            num = num / 2;
            length++;
        } else {
            num = num * 3;
            num++;
            length++;
        }
    }
    return length;
}

long longestCollatzSequence(long topLim)
{
    /*
    while num<1million, run num through a collatz machine
        If num > largestResult of Collatz machine
            LR = num
    */
    long largestResult = 0;
    long lastOut = 0;
    for (long num = 1; num < topLim; num++)
    {
        long collatz = collatzMachine(num);
        if (collatz > largestResult)
            largestResult = collatz;

        if (largestResult > lastOut)
        {
            cout << largestResult << endl;
            lastOut = largestResult;
        }
        cout << num << endl;
    }
    return largestResult;
}

int main()
{
    cout << longestCollatzSequence(1000000) << endl;
    return 0;
}
