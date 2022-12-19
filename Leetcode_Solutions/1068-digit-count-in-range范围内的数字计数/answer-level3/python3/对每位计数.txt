原理跟前一个题解差不多，几点注释：
1. slow前面加零，否则不能取元素
2. k表示数位，个位为0，十位为1，以此类推
3. mult是完全在low和high之间的当前位的数量
4. 0在小数前面不用数（13行）


时间复杂度：O(log(high))


空间复杂度：O(log(high))
```
class Solution:
    def digitsCount(self, d, low, high):
        ans=0
        sd,slow,shigh=str(d),'000000000'+str(low),str(high)
        for k in range(len(shigh)):
            unit=10**k
            mult=1+high//(unit*10)-low//(unit*10)
            if slow[-k-1]>=sd:
                mult-=1
            if shigh[-k-1]<=sd:
                mult-=1
            ans+=mult*unit
            if slow[-k-1]==sd and (d!=0 or low>=unit):
                ans+=unit-low%unit
            if shigh[-k-1]==sd:
                ans+=high%unit+1
        return ans
```
