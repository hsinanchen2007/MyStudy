### 解题思路
按正常编程思路,搜索是第一解法.按数学题来做,一个问题就是怎么找出操作序列?
也就是说ax+by=z的解有什么实际含义?
以x = 5, y = 7,z = 1为例
考虑两个无限高的桶,但这俩个桶有刻度,桶1的一个刻度表示5,桶2的一个刻度表示7
方程5a+7b=1的解为(3,2)
![无标题.png](https://pic.leetcode-cn.com/4cb9b5eeb4ee403521939b8d08bf26923d878255b3648b63904e4112237ab22a-%E6%97%A0%E6%A0%87%E9%A2%98.png)

从图中可以看到,两个大小为7的块填充3个大小为5的块之后,3各大小为5的块还剩下1
也就是说,用三个5升水的桶去装二个7升水的桶,最后剩下一升水,这就是答案
**实际上,由于桶中水满之后把水倒掉的操作也可以看作加了一个新桶,所以无限有刻度的桶和有限无刻度的桶这两种模型是等价的.**
这样的操作序列也就不难想到.若方程的解是一正一负,那就是用正数个正数对应的桶去装负数绝对值个负数对应的桶.
若都是正数,那就只有一种可能:都装满


### 代码

```python
class Solution(object):
    def canMeasureWater(self, x, y, z):
        """
        :type x: int
        :type y: int
        :type z: int
        :rtype: bool
        """     
        def gcd(x,y):
            if y==0:return x
            return gcd(y,x%y)
        g = gcd(max(x,y),min(x,y))
        return z in range(0,x+y+1,g) if g!=0 else z==0
```