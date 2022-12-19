## 思路
如果不是快乐数，递归判断过程中就会重复出现，所以可以通过集合判断是否重复出现某个数。

### 代码
```c++
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> uset;
        while (n != 1) {
            if (uset.count(n) > 0) {
                return false;
            }
            uset.insert(n);
            n = helper(n);
        }
        return true;
    }

    int helper(int n) {
        int res = 0;
        while (n != 0) {
            res += pow(n % 10, 2);
            n /= 10;
        }
        return res;
    }
};
```
