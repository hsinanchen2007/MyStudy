回文串的组成有两种：
**1 由全部为偶数个的不同字符组成'sdffds' 
2 在中间加一个字符'sdfds'**
所以计算字符串中每个字符的偶数数（要是有7个则count加上6要是有4个则count加上4），要是count与字符串的长度一致则返回count（第一种） 否则返回count+1（第二种）

```
def longestPalindrome(self, s: str) -> int:
        count=0
        for i in set(s): #利用set的去重特性
            count+=s.count(i)//2*2
        return count if count==len(s) else count+1
```
