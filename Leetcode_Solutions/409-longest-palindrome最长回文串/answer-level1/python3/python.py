
思路：出现偶次数直接相加，奇次数减一再相加。如果存在出现奇次数的字符，最中间一位一定是奇次数的字符，长度还要再加一，所以加个flag判定是否存在出现奇次数的字符
```
class Solution:
    def longestPalindrome(self, s: str) -> int:
      
        ans=0
        flag=0
        count=collections.Counter(s)
            
        for value in count.values():
            if value%2==0:
                ans+=value
            else:
                flag=1
                ans+=value-1
        if flag==1:
            ans+=1
        return(ans)
```

