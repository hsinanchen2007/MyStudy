## 思路


### 代码
时间复杂度：O(10^n)
空间复杂度：O(1)
```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int max = pow(10, n);
        for (int i = 1; i < max; ++i) {
            res.push_back(i);
        }
        return res;
    }
};
```