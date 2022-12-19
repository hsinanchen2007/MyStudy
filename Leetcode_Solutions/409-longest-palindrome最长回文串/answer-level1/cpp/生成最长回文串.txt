

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map <char,int> mp;
        for(int i=0;i<s.length();i++)
        {
            ++mp[s[i]];
        }//记录每个字符出现次数
        int res=0;
    for(auto count : mp)
    {
        int p=count.second;
        res+=p/2*2;  //左右对称放偶数个该字符；
        if(res%2==0&&p%2==1) //如果这个字符有奇数个并且当前串长为偶数（中间还没有被放上过对称轴），则放上对称轴字符，串长加1；（注意：这里对称轴放的是遇到的第一个次数为奇数的字符，以后再次遇见的奇数次的字符都不再放，因为是对称轴的字符只可能有一个）
        res=res+1;
    }
    return res;
    }

    
};
```