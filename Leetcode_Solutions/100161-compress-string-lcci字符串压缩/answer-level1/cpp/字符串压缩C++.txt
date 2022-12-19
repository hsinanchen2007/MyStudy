### 解题思路
此处撰写解题思路
![捕获.PNG](https://pic.leetcode-cn.com/899526cd205602b456fa623922ebf700f37fc131d776b1367e4eceb32abaf7ed-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```cpp
class Solution {
public:
    string compressString(string S) {
        int len_pre = S.size();
        if (len_pre < 2) return S;
        string res;
        auto t = S[0];
        int num = 1;
        for (int i = 1; i < len_pre; i++) {
            if (t == S[i]) {
                num++;
            }
            else {
                res += t;
                res += to_string(num);
                t = S[i];
                num=1;
            }
        }
        res += t;
        res += to_string(num);
        return (res.size() >= S.size())?S:res;

    }
};
```