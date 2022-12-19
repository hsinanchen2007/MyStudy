### 思路：
1、计算当前这个与前面字符是否相同，并记录个数，curLen
2、when当前的字符与前面的字符不相同时，将前面字符的个数保存,preLen
3、当preLen>=curLen时，说明存在01和0011这两种情况中的一种，所以个数count=1
### 代码
```
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
         n = len(s)
         if n<=1:
             return 0
        ##记录当前重复字符串的个数
         curLen = 1
         preLen = 0
        ##记录子串的个数
         count = 0

         for i in range(1,n):
             if s[i]==s[i-1]:
                curLen+=1
             else:
                preLen=curLen
                curLen=1
             if preLen>=curLen:##preLen>=curLen:很重要，if only 等于，则只有0011的情况，当存在>情况时，就存在01这种情况。仔细读一下代码即可
                count+=1
                
         return count
```
