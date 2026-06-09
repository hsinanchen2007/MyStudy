### 解题思路
观察规律确定
1. 字符串从头至尾放入不同行
2. 行数达到numRows时，递减当前行数；行数达到0时，递增当前行数
时间复杂度O(n2)
### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res;
        size_t sz = s.size();
        res.reserve(sz);
        for (int row = 0; row < numRows; ++row) {
            int i = row;
            int cur = row;
            int flag = 1;
            while (i < sz) {
                if (cur == row) {
                    res.push_back(s[i]);
                }
                if (cur == numRows - 1) {
                    flag = -1;
                } 
                if (cur == 0) {
                    flag = 1;
                }
                cur += flag;
                ++i;
            }
        }
        return res;
    }
};
```