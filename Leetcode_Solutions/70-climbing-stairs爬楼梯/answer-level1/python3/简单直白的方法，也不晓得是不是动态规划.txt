### 解题思路
此处撰写解题思路
看了题的小伙伴应该都懂，最终的路径数等于倒数第二和倒数第三的路径数之和。
所以就简单把上面的文字翻译成代码即可（当然，需要初始的列表是[1，2]所以要把n=1的情况单列出来
剩下的就很简单了，我是直接给了个无限循环当列表长度=n时跳出循环，然后一直添加最后两个元素之和
最后返回列表的最后一个元素就ok了
### 代码

```python3
class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        dp = [1,2]
        while True:
            if len(dp) == n:
                break
            dp.append(dp[-1]+dp[-2])
        return dp[-1]

```