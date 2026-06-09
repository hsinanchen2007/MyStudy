```
class Solution
{
private:
    bool isPrime(int N)
    {
        if(N<=1)
            return false;
        for(int i=2; i<=sqrt(N); i++)
        {
            if(N%i==0)
                return false;
        }
        return true;
    }
    int reverse(int N)
    {
        int sum=0;
        while(N)
        {
            sum = sum * 10+ N % 10;
            N = N / 10;
        }
        if(sum > INT_MAX||sum<INT_MIN)
            return 0;
        return sum;
    }
    bool isPalindromic(int N)
    {
        if(N<0)
            return false;
        if(N>=0&&N<=9)
            return true;

        if(reverse(N) == N)
            return true;
        else
            return false;
    }
    // A utility function to check if num has all 9s
    int AreAll9s( vector<int> num, int n )
    {
        int i;
        for( i = 0; i < n; ++i )
            if( num[i] != 9 )
                return 0;
        return 1;
    }


// Returns next palindrome of a given number num[].
// This function is for input type 2 and 3
    void generateNextPalindromeUtil (vector<int>& num, int n )
    {
        // find the index of mid digit
        int mid = n/2;

        // A bool variable to check if copy of left side to right is sufficient or not
        bool leftsmaller = false;

        // end of left side is always 'mid -1'
        int i = mid - 1;

        // Beginning of right side depends if n is odd or even
        int j = (n % 2)? mid + 1 : mid;

// Initially, ignore the middle same digits
        while (i >= 0 && num[i] == num[j])
            i--,j++;

        // Find if the middle digit(s) need to be incremented or not (or copying left
        // side is not sufficient)
        if ( i < 0 || num[i] < num[j])
            leftsmaller = true;

        // Handle the case where middle digit(s) must be incremented.
        // This part of code is for CASE 1 and CASE 2.2
        if (leftsmaller == true)
        {
            int carry = 1;
            i = mid - 1;

            // If there are odd digits, then increment
            // the middle digit and store the carry
            if (n%2 == 1)
            {
                num[mid] += carry;
                carry = num[mid] / 10;
                num[mid] %= 10;
                j = mid + 1;
            }
            else
                j = mid;

            // Add 1 to the rightmost digit of the left side, propagate the carry
            // towards MSB digit and simultaneously copying mirror of the left side
            // to the right side.
            while (i >= 0)
            {
                num[i] += carry;
                carry = num[i] / 10;
                num[i] %= 10;
                num[j++] = num[i--]; // copy mirror to right
            }
        }
        else
        {
            // Copy the mirror of left to tight
            while (i >= 0)
            {
                num[j++] = num[i--];

            }
        }
    }
    /* Utility that prints out an array on a line */
    void printArray(vector<int> num, int n)
    {
        int i;
        for (i=0; i < n; i++)
            printf("%d ", num[i]);
        printf("\n");
    }
// The function that prints next palindrome of a given number num[]
// with n digits.
    void generateNextPalindrome( vector<int>& num, int n )
    {
        int i;

      //  printf("Next palindrome is:");

        // Input type 1: All the digits are 9, simply o/p 1
        // followed by n-1 0's followed by 1.
        if( AreAll9s( num, n ) )
        {
            num.clear();
            num.resize(n+1);
            num[0]=1;
            num[n]=1;
            for(int i = 1; i < n; i++ )
                num[i]=0;
        }

        // Input type 2 and 3
        else
        {
            generateNextPalindromeUtil ( num, n );

            // print the result
           // printArray (num, n);
        }
    }

public:

    int vectorIntToInt(vector<int> num)
    {
        std::reverse(num.begin(), num.end());
        int decimal = 1;
        int total = 0;
        for (auto& it : num)
        {
            total += it * decimal;
            decimal *= 10;
        }

        return total;
    }
    vector<int> intToVectorInt(int N) {
        int i=N;
        vector<int> num;
        int count = 0;
        while(N)
        {
            N=N/10;
            count++;
        }
        num.resize(count);
        int j=count-1;
        while(i)
        {
            num[j] = i%10;
            i=i/10;
            j--;
        }
        return num;

    }
    int primePalindrome(int N)
    {
        int k=N;
        while(k<2*pow(10,8))
        {
            if(isPalindromic(k))
            {
                if(isPrime(k)){
                    break;
                }
                else{
                    k++;
                }

            }
            else
            {
                //k---->vec
                vector<int> vec =  intToVectorInt(k);
                int n=vec.size();
                generateNextPalindrome(vec,n);
                k = vectorIntToInt(vec);
            }
        }
        return k;
    }
};
```

