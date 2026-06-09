### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numPrimeArrangements(int n) {
        if (n <= 0) {
            return 0;
        }
        int prime_num = 0;
        for (int i = 2; i <= n; ++i) {
            if (IsPrime(i)) {
                prime_num += 1;
            }
        }
        int other_pos = n - prime_num;
        if (other_pos < prime_num) {
            swap(other_pos, prime_num);
        }
        int mod_num = Power(10, 9) + 7;
        long int total = 1;
        for (int i = 2; i <= prime_num; ++i) {
            total *= i;
            if (total > mod_num) {
                total %= mod_num;
            }
        }
        //为防止溢出, 需两次取余
        total %= mod_num;
        total *= total;
        total %= mod_num;
        while (other_pos > prime_num) {
            total *= other_pos;
            other_pos -= 1;
            if (total > mod_num) {
                total %= mod_num;
            }
        }
        return total;
    }
    bool IsPrime(const int val) {
        int st = sqrt(val);
        for (int i = 2; i <= st; ++i) {
            if (val % i == 0) {
                return false;
            }
        }
        return true;
    }
    int Power(int base, int count) {
        int total = 1;
        while (count > 0) {
            total *= base;
            count -= 1;
        }
        return total;
    }
};
```