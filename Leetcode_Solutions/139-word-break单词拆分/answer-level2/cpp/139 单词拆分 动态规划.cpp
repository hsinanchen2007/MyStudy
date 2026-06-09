### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/cdffcfb2a0c0bc1ddf531d7fe0ac76670531c89689f0e7fa014c5a8a3a4715f2-image.png)

开始用回溯法，超时了
改为动态规划
其实由于可以重复用，那么动态规划明显好一些
转移方程
若
s.substr(i, l) == word
则
if (i == 0 || v[i - 1]) v[i + l - 1] = true;
整个字符串为v[len - 1];
### 代码

```cpp
class Solution {
public:
    //回溯法超时了，用动态规划
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int len = s.size();
        vector<bool> v(len, false);
        for (int i = 0; i < len; i++) {
            for (auto word : wordDict) {
                int l = word.size();
                if (i + l - 1 >= len) continue;
                if (s.substr(i, l) == word) {
                    if (i == 0 || v[i - 1]) {
                        v[i + l - 1] = true;
                    }
                }
            }
        }
        return v[len - 1];
    }
};
```