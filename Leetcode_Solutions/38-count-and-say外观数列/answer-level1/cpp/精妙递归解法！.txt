### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string countAndSay(int n) {

        if (n == 1) return "1"; // 递归终止条件 (递归到底的情况) ... 

        string s = countAndSay(n - 1) + ' '; // 精妙 ... 递归调用... 
        stringstream ss;
        
        int i = 0, j = 0; // 构建递推过程 ...
        while (j < s.size() - 1) {
           if (s[j + 1] != s[i]) {
               ss << char(j - i + 1 + '0') << s[i];
               i = j + 1;
           }
           j++;
        }

        return ss.str();
    }
};
```