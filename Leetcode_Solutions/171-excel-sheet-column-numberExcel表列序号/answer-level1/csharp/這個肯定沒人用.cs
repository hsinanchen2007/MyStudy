### 解题思路
最近重學遞迴，結果看題第一時間想到的都是遞迴解...
看題解才發現自己多智障...
但速度還是100%

### 代码

```csharp
public class Solution {
    public int TitleToNumber(string s) {
        if(s.Length==0) return 0;
        Dictionary<char,int> dict = new Dictionary<char,int>();
        for(int i=0;i<26;++i)
        {
            dict.Add((char)('A'+i),i+1);
        }
        return calculator(dict,s.Length-1,s);
    }
    public int calculator(Dictionary<char,int> dict,int n,string s)
    {
        int res = 0;
        res+=(n==0) ? dict[s[n]] : calculator(dict,n-1,s)*26+dict[s[n]];
        return res;
    }
}
```