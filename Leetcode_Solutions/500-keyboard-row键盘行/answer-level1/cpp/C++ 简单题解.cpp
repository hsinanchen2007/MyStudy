### 解题思路
1，记录每一个单词的行号
2，判断单词中字母是否是同一行中的即可

### 代码

```cpp
class Solution {
public:
    int rows[26] = {1, 2, 2, 1, 0, 1, 1, 1, 0, 1, 1, 1, 2, 2, 0, 0, 0, 0, 1, 0, 0, 2, 0, 2, 0, 2};
    char lower(char c) {
        return c <= 'Z' ? c - 'A' + 'a' : c;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for (auto& w : words) {
            int i = rows[lower(w[0]) - 'a'];
            bool valid = true;
            for (int j = 1; j < w.size(); ++j) {
                if (rows[lower(w[j]) - 'a'] != i) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                res.push_back(w);
            }
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/a61c29ee8b0d53baf9124710c1cfcd63bd55cf10b06c7ab5308749a2011c9ac8-image.png)
