```cpp
bool isPrime(int num)
{
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return false;
    
    return true;
}

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for (int i = L; i <= R; ++i) {
            int tmp = i, cnt = 0;
            while (tmp) {
                tmp &= tmp - 1;
                ++cnt;
            }
            if (isPrime(cnt)) ++res;
        }
        return res;
    }
};
```