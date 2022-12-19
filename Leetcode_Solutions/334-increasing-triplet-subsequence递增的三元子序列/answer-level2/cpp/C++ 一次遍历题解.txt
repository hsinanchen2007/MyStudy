### 解题思路
一次遍历，不断更新3个数，直到三数满足条件为止

### 代码

```cpp
class Solution {
public:
    const long INF = 1e10;
    bool increasingTriplet(vector<int>& nums) {
        long n1 = INF;
        long n2 = INF;
        long n3 = INF;
        for (auto x : nums) {
            if (x < n1) {
                n1 = x;
            } else if (x != n1 && x < n2) {
                n2 = x;
            } else if (x != n1 && x != n2 && x < n3) {
                n3 = x;
            }
            if (n1 < n2 && n2 < n3 && n3 < INF) {
                return true;
            }
        }
        return false;
    }
};
```

![image.png](https://pic.leetcode-cn.com/0af94be5460fad4407207557c1e306918cbdc46c82f09eadef7b70d539c55759-image.png)
