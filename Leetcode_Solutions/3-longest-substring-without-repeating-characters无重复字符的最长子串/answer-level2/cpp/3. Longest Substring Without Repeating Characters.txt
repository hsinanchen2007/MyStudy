### 解题思路
* 遍历字符串，用数组标记字符出现的位置；
* 标记无重复子字符串的起始位置left；
* 发现字符已经被标记过位置（mark[c] > 0），而且发现的字符在起始位置left的右边（mark[c] > left），修改起始位置；
* mark[c] < left，表明字符c出现在已经重复的字符c'的左边，无意义；
* 当前子字符串长度是 i - left + 1

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest =  0;
        unordered_map<char, int> mark;
        int left = 0;
        for(int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if(mark[c] > 0 && mark[c] > left) {
                left = mark[c];
            }
            mark[c] = i + 1;
            longest = max(longest, i - left + 1);
        }
        return longest;
    }
};
```
![3.png](https://pic.leetcode-cn.com/448e60fc4a0e885b9978df9a82a5129326b442b5a60073fee6cb1d153ac6392d-3.png)
