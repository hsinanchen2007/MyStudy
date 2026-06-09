### 解题思路
显然可知，字符数为偶数的必定可构成回文串。而奇数方面，只要个数不为1，可将个数-1的字符构成回文串，最后再加上单个字符即可解答。

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.size();++i)
        {
            m[s[i]]+=1;
        }
        int res=0;
        int max_odd=0;
        int yes=0;
        for(auto i=m.begin();i!=m.end();++i)
        {
            if(i->second%2==0)
            {
                res+=i->second;
            }
            if(i->second%2==1&&i->second>2)
            {
                res+=(i->second-1);
                yes=1;
            }
            if(i->second==1)yes=1;
        }
        res+=yes;
        return res;
    }
};
```