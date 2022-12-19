### 解题思路
1   5   9      r0+4 ...
2 4 6 8 10     r1+2 r1+2 ...
3   7   11     r2+4 ...

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if (numRows == 1 || size <= numRows) return s;
        string res;
        res.reserve(size + 1);
        char* src = (char*)s.data();
        char* dst = (char*)res.data();
        dst[size] = '\0';
        for (int i = 0; i < numRows; ++i) {
            int a = (numRows - 1 - i) * 2;
            int b = i * 2;
            int idx = i;
            *dst++ = src[idx];
            while (idx < size) {
                if (a) {
                    idx += a;
                    if (idx < size) *dst++ = src[idx]; 
                }
                if (b) {
                    idx += b;
                    if (idx < size) *dst++ = src[idx];
                }
            }
        }
        return res;
    }
};
```