### 解题思路
最长回文字符串,观察特征
发现规律:每两个相同的字符串就可以构成一个回文字符串,
最中间的那个数字可以是奇数个,判断结果大小与原字符串大小,小的话就加1,就是回文字符串最中间的那个字符.

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> result;
        //判断长度是否小于等于1,直接返回字符串长度
        if (s.length() <= 1) return s.length();
        int length = s.length();
        int resultLength = 0;

        //用一个map表记录键值对,如果出现个数为偶数个,就给结果加2
        for (int i = 0; i < length; i++)
        {
            if (result.find(s[i]) != result.end())
            {
                if ((++result[s[i]]) % 2 == 0)
                    resultLength += 2;
            }
            else
            {
                result.insert(pair<char, int>{s[i], 1});
            }
        }
        //判断当前长度是否和字符串长度相等,如果小就加1.
        if (resultLength < length)
            resultLength++;
        return resultLength;
    }
};
```