### 解题思路
直接求出n位数+1作为顶，这个刚好是10的n次方。

### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        int max = pow(10, n);
        vector<int> res;
        for (int i=1; i<max; i++) {
            res.emplace_back(i);
        }
        return res;
    }
};
```