### 解题思路
此处撰写解题思路
此题只需要计算出最长回文串的长度，所以我们只需要统计每一个字母的数量即可；
一共要考虑3种情况：
（1）字母个数全部为偶数；
（2）有一个字母的数量为奇数，其余全为偶数；
（3）奇数和偶数个的字母数量都大于一；
因为最终回文串中只可能出现一个奇数个的字母，所以要把其余的全部减去一变为偶数。

具体代码如下，其中包括主要的代码注释。
### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) 
    {
        if(s.empty()) //当s为空
            return 0;

        unordered_map<char, int> m; //统计每一个字母的个数
        for(char ch:s)
            ++m[ch];

        int length = 0;
        bool odd = false; //判断是否存在奇数个的字母
        /*
        最长回文串一定是所有偶数个字母加上所有奇数个字母减一（最长奇数字母不需减一，有一个放在中间）
        */
        for(auto t = m.begin(); t != m.end(); t++)
        {
            if(t->second%2 == 0)
                length += t->second;
            if(t->second%2 == 1)
            {
                odd = true;                
                length = length + t->second - 1;
            }
                
        }
        if(odd == true) //如果存在奇数个的字母，则需要额外加一
            length++;

        return length;
    }
};

```