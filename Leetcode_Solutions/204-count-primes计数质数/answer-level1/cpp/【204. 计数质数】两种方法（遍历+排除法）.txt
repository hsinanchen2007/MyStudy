### 思路一：遍历

### 代码

```cpp
class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        for (int i = 1; i < n; ++i) {
            if (isPrime(i)) ++cnt;
        }
        return cnt;
    }

    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }
};
```

### 思路二：排除法
用一个vector表示当前数是否是质数，从2开始遍历，先找到第一个质数，然后将所有2的倍数的数标记为false。

### 代码
```c++
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<bool> prime(n, true);
        for (int i = 2; i < n; ++i) {
            if (!prime[i]) continue;
            ++res;
            for (int j = 2; i * j < n; ++j) {
                prime[i * j] = false;
            }
        }
        return res;
    }
};
```
