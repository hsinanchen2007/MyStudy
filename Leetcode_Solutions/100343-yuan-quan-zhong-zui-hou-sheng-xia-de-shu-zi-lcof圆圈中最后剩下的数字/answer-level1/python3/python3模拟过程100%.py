![image.png](https://pic.leetcode-cn.com/7d028e927805970dd410cc7527e94e063afa855038da74abc05ddd481e6625ee-image.png)
想法很简单，有朋友问了到底用m % n - 1作x循环还是用 m - 1% n作循环
其实是一个基础的数学逻辑问题，记住在引起变化处还原它，而不是外层或其他
代码如下
```
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        Circle = [i for i in range(n)]
        last = 0
        # 有朋友问了 2%5 还是 3%5-1？ 
        #这里的数学差距源于算术(常识)上的第一个值为1但在数据结构中我们认为第一个是0，这样在运用m的地方
        #内层，做好这个处理。这样后面的问题都会处理好这个问题。
        first_index = (m - 1) % n
        index = first_index
        while len(Circle) > 1:
            Circle.pop(index)
            last = index
            index = (last + m -1) % len(Circle)
        return Circle[0] 


```
