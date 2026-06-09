### 解题思路
1、先定义一个str，直接遍历原字符串s，然后不断的把s添加到str里
2、每次添加的时候，都要先使用find函数，查一下这个字符有没有出现过
3、如果出现过，则使用substr截取，假设之前出现的位置是a1，那么就截取a1到str的末尾
4、然后把当前的字符继续加到str后
5、执行完第4步后计算一下当前的str的长度，保存最长的
### 代码

```cpp
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.length() == 0)
            return 0;
        int maxLen = 0;
        string str = "";
        for (int i = 0; i < s.length(); ++i)
        {
            if (str.find(s[i]) >= 0 && str.find(s[i]) <= str.length())
            {
                str = str.substr(str.find(s[i]) + 1, str.length());
            }
            str += s[i];
            if (str.length() > maxLen)
                maxLen = str.length();
        }
        return maxLen;
    }
};
```