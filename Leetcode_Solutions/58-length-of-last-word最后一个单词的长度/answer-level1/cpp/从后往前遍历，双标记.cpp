### 解题思路
从后遍历，先找到第一个不是空格的，那就是最后一个单词的末尾
然后这里给最后一个单词的初始位置赋值相同的值
继续遍历，找到空格就退出即可
时间复杂度O(n)

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }
        size_t last_not_space = string::npos;
        size_t begin = string::npos;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (last_not_space == string::npos) {
                if (s[i] == ' ') {
                    continue;
                } else {
                    last_not_space = i;
                    begin = i;
                    continue;
                }
            } else {
                if (s[i] != ' ') {
                    begin = i;
                } else {
                    break;
                }
            }
        }
        if (last_not_space == string::npos) {
            return 0;
        }
        if (begin == string::npos) {
            return 0;
        }
        return (last_not_space - begin + 1);
    }
};
```