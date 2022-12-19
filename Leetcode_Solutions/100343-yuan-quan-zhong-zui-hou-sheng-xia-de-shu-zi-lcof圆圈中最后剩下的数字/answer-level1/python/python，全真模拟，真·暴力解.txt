### 解题思路
这个游戏里叫击鼓传花，西方也有叫热土豆。可通过严格的数学推导直接计算得出。但我们用程序来全真模拟才更真实。
1. 生成一个0、1、…、n-1的列表，初始索引`i=0`
2. 传递m次，意味着从i开始偏移m得到新索引`i=i+m-1`，考虑m可能大于当前列表长度，所以要对列表长度求模余
3. 从列表中pop出一个值后，实际上下一次偏移的初始索引未改变（因为后边的值都前移了一位），所以仍然是用`i=i+m-1`迭代新的索引，当然也要用新的列表长度求模余
4. 直至列表长度为1，返回最后剩下的数字。

由于列表中`pop(i)`是平均`O(n)`复杂度，所以总的时间复杂度是O(n2)

### 结果
![image.png](https://pic.leetcode-cn.com/573236ee64cea3564740360077b9884d985817f553ca1e79f6afbcaf95b80350-image.png)

### 代码

```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        i, a = 0, list(range(n))
        while len(a)>1:
            i = (i+m-1)%len(a)
            a.pop(i)
        return a[0]
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)
