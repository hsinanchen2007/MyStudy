### 解题思路
用一个变量 表示往上走还是往下走

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> arr(numRows, "");
        int j = 0; 
        int step = 1;
        for(int i = 0; i < s.size(); ++i) {
            if(j == 0) step = 1;
            else if(j == numRows - 1) step = -1;
            arr[j] += s[i];
            j += step;
        }

        string res;
        for(int i = 0; i<numRows; ++i) {
            res += arr[i];
        }
        return res;
    }
};
```