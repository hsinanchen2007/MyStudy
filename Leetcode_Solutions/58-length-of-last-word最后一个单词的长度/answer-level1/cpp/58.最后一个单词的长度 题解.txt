### 解题思路
一开始想着就是遍历字符串，思路是每遇到一个单词的第一个字符就开始统计这个单词的长度，然后找到最后的这个单词就可以了，后来一下子想到，反过来逆序遍历不就好了，而且只需要遍历完逆序的第一个单词即可结束遍历，实现起来很简单

### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] != ' ')
                length++;
            if (s[i] == ' ' && length != 0)
                break;
        }
        return length;
    }
};
```