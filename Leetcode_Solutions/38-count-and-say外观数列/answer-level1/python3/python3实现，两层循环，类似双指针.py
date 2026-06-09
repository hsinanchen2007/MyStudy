say函数为内循环，根据当前字符串求得下一字符串，使用双指针方法实现，i为慢指针，j为快指针
主函数为外部循环，迭代题目要求次数即可
总体时间复杂度为O(n*len(s))

```
class Solution:
    def countAndSay(self,n):
        s='1'
        for i in range(n-1):
            s=self.say(s)
        return s

    def say(self,s):
        res=''
        i=0
        for j in range(len(s)):
            if s[j]!=s[i]:
                res+=str(j-i)+s[i]
                i=j
        res+=str(len(s)-i)+s[i]
        return res
```
