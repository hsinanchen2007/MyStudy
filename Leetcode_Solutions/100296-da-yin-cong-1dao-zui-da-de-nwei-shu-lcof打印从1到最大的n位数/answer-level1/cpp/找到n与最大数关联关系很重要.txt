### 解题思路
输入n虽然并不是直接需要遍历的数字，但存在着关联关系，这个关系就是：
- n = 1, 最大值`10^1 - 1`
- n = 2, 最大值为`10^2 - 1`
- ....依次类推得到公式 `10^n -1`

### 代码

```cpp
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        for(int i = 1; i < pow(10, n); i++) {
            res.push_back(i);
        }

        return res;
    }
};
```