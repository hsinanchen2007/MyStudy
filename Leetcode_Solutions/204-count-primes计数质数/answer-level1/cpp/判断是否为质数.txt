``` C++ 
class Solution {
public:
    int countPrimes(int n) {
        int count=1;
        if(n<3) return 0;
        for(int i=3;i<n;i+=2)
        {
            if(isPrime(i))
                count++;
        }
        return count;
    }
    bool isPrime(int n)
    {
        if(n==2)
            return true;
        if(n%2==0)
            return false;
        for(int i=3;i<=sqrt(n);i+=2)//此处减少计算次数，直接i++超时
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
};
```
