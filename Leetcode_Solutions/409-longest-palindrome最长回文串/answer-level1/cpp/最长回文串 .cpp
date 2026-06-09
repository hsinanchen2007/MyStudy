### 解题思路
用map将字母及其出现次数存起来。
如果出现次数为偶数的话，就直接将该次数加到res中
如果出现次数为奇数的话，就在res中加上该次数减1.
同时还要注意，只要有一个字母出现的次数为奇数，就要在最后结果中加1。(将该字母放到字符串的中间)，为了实现这一点，定义一个变量cnt，当一个变量出现的次数为奇数时，将cnt置1。

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        int res=0;
        int cnt=0;
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
        for(int i=0;i<m.size();i++)
        {
            if(m[i]&1)
            {
                res+=(m[i]-1);
                cnt=1;
            }
            else
                res+=m[i];
        }
        return res+cnt;
    }
};

```