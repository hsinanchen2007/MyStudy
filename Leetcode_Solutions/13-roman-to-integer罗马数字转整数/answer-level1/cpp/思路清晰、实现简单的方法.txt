罗马数字转换为阿拉伯数字的时候，实际上是从左到右将每个字符对应的值累加的过程。例如“XVI”，实际就是10（X）+5（V）+1（I）。

只不过由于存在特殊规则增加了这个过程的复杂，不过同样可以用上面的思路解决。举个例子，“IX”，可以看作是-1+10=9；“XIX”可以看作是10-1+10=19。

题目又告诉我们，通常情况下，罗马数字中小的数字在大的数字的右边。所以，如果s[i]<s[i+1]，那s[i]在累加时需要加一个负号，这就完成了特殊规则的处理。

AC代码：
```
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        
        int pos = 0, neg = 0;
        for (int i = 0;i < s.size()-1;++i){
            if (mp[s[i]] < mp[s[i+1]])
                neg -= mp[s[i]];
            else
                pos += mp[s[i]];
        }
        pos += mp[s.back()];
        
        return pos + neg;

           
    }
};
```
