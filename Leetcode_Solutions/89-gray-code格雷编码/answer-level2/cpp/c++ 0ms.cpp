### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.reserve(1 << n);
        result.push_back(0);
        for (int i = 1; i <= n; ++i) {
            int mask = 1 << i-1;
            for (int i = result.size()-1; i >= 0; --i) {
                result.push_back(result[i] | mask);
            }
        }
        return result;
    }
};
```