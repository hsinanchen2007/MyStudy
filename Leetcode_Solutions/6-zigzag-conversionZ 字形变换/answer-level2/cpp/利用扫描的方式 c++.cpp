``` c++
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows >= s.size() || numRows == 1) return s; // 一维的特殊情况
        string res;
        int left = (numRows - 1) * 2;
        int right = 0;
        
        for (int i=0; i<numRows; i++) {
            res += s[i];
            int j = i;
            while (j < s.size()) {
                if (left > 0) { // 左间隔存在时才打印，考虑了第一行的特殊情况
                    j += left;
                    if (j < s.size()) res += s[j]; // 超出字符串范围的不打印
                }
                if (right > 0) {  // 右间隔存在时才打印，考虑了最后一行的特殊情况
                    j += right;
                    if (j < s.size()) res += s[j]; // 超出字符串范围的不打印
                }
            }
            left -= 2;
            right += 2;
        }
        return res;
    }
};
```
