### 解题思路
首先考虑string长度为0和1的情况单独列出。

题目要求输出最长无重复子串的长度，可以用变量max保存长度，max初始化为1。
用i记录字串最左边位置，j记录最右边位置，k作为循环变量遍历查找字串中是否有重复元素。
一个遍历下来，
1.若有重复值，左边位置i=k+1，右边位置j++；
2.若无重复值，左边位置i不变，右边位置j++；
计算新字串长度（j-1），并与max比较，得到新的最大长度。


### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        if(s.size() == 1)
            return 1;

        int max = 1;
        int i = 0, j = 1, k;
        while(j < s.size())
        {
            for(k = i;k < j;k++)
            {
                if(s[k] == s[j])
                {
                    i = k + 1;
                    break;
                }
            }
            j++;
            if(j-i > max)
                max = j-i;
        }
        return max;
    }
};
```