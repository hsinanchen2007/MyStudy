执行用时 :28 ms, 在所有 python3 提交中击败了100.00%的用户
内存消耗 :12.7 MB, 在所有 python3 提交中击败了99.45%的用户
我认为此方法值得一看

规定x代表第n-1项数列,y代表第n项数列,即y是x的下一次报数
初始利用pre记录x的第一个字符即pre=x[0],利用count来记录pre出现的次数

遍历x的每一个字符
- 当**x[e]==pre**,我们将count加一
- 当**x[e]!=pre**,我们将str(count)+pre加在y的最后面,即y+=str(count)+pre,最后对count和pre进行重置

注意当循环结束后,我们还需要进行一次y+=str(count)+pre
```py
class Solution:
    def countAndSay(self, n: int) -> str:
        if n==1:
            return "1"
        else:
            x=self.countAndSay(n-1)
            y=""
            pre=x[0]
            count=1
            for e in range(1,len(x)):
                if x[e]==pre:
                    count+=1
                    continue
                else:
                    y+=str(count)+pre
                    count=1
                    pre=x[e]
            y+=str(count)+pre
            return y
```
