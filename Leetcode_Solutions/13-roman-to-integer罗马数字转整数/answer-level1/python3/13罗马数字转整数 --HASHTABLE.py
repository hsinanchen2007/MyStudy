### 解题思路
依据罗马数字的规则，前面数字加后面数字，如果前面数字小于后面数字，则再减去后面的数字*2。
如IVX：
IV: I+V=1+5=6 => (I<V) 6-I*2=6-1*2=4
IVX: IV+X=4+10=14 =>（V<X）14-V*2=14-5*2=4
### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        HT={'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        #special case
        if not s:return 0#字符串为空->返回0
        if len(s)<2:return HT[s]#只有一个字符，查表返回
        #字符大于1，先将首字母查表；再从索引1开始向后查询，每次加上当前数字之后比较与上个字符查表的大小，
        #若当前数字大于上一个数字，则减去上一个数字*2
        res=HT[s[0]]
        for i in range(1,len(s)):
            res+=HT[s[i]]
            if HT[s[i-1]]<HT[s[i]]:
                res-=HT[s[i-1]]*2
           
        return res
```