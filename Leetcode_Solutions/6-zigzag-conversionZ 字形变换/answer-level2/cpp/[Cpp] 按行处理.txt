### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        if (numRows == 1) return s;
        // 算出相邻两个竖行之间相隔了几个元素
        int jump = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            int j;
            // 第0行和最后一行两个竖行之间没有元素
            if (i == 0 || i == numRows - 1) {
                for (j = i; j < s.size(); j += jump) res += s[j];
            } else {
                // 其余行，两个竖行之间插入一个元素，其位置为
                // 右边竖行的idx - ((i + 1) - (i - 1)) == idx - 2*i
                for (j = i; j < s.size(); j += jump) {
                    res += s[j];
                    int t = j + jump - (2 * i);
                    if (t < s.size()) res += s[t];
                }
            }
        }
        return res;
    }
};
```