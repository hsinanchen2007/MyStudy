![捕获.PNG](https://pic.leetcode-cn.com/79406330b1641286b858b4cb23958c66ff6bc6cbddf5e30709e48187e7c5673a-%E6%8D%95%E8%8E%B7.PNG)

```cpp
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> hash;
        return isHappy(n, hash);
    }
    
    bool isHappy(int n, unordered_map<int, bool>& hash) {
        if (n == 1) {hash[n] = true; return hash[n];}
        if (n == 4) {hash[n] = false; return hash[n];}
        if (hash.find(n) != hash.end()) return hash[n];
        if (isHappy(getSquareSum(n), hash)) hash[n] = true;
        else hash[n] = false;
        return hash[n];
    }
    
    int getSquareSum(int x) {
        int sum = 0;
        while (x != 0) {
            int remainder = x % 10;
            sum += remainder * remainder;
            x /= 10;
        }
        return sum;
    }
};
```