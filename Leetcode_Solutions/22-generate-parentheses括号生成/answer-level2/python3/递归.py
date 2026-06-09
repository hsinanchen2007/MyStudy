这个题，一开始就想到递归。n组括号的组合，可以给予n-1的组合的每一个元素上加一对括号。

关键点在于加一对括号怎么加。
一开始想到的是在左边加，在右边加，然后最外围加，用set实时去重就可以
用这种规则，算出来，发现会少一种情况，(())(())，这个括号对，按照上面的规则，是加不出来的；一只苦苦思索没有办法解决；

看到@YueChunyu的评论说道，可以在任意位置插入，突然豁然开朗。


```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return []
        elif n == 1:
            return ["()"]
        else:
            rest = self.generateParenthesis(n-1)
            result = set()
            for item in rest:
                for i in range(len(item)):
                    t = item[:i] + "()" + item[i:]
                    if t not in result:
                        result.add(t)
            
        return result
            
```



