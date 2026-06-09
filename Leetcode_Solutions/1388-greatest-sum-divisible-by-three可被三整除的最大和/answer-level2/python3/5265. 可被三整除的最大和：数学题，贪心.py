![image.png](https://pic.leetcode-cn.com/5278d11d0915356393e9098ca1578c77044588f3d366a0e1dfb723062c72ff73-image.png)


先求出`nums`的和`s`，然后通过`s % 3`求出余数`k`：

如果余数`k = 1`，那就从`nums`中找出余数为`1`的最小值，以及最小的2个余数为`2`的数的和；

反之余数`k = 2`，那就从`nums`中找出余数为`2`的最小值，以及最小的2个余数为`1`的数的和；

`s`减去这两个数里较小的那个就可以了。

代码里面找2个最小值的时候用了个堆，不用堆也可以，反正求出最小的两个值之和就行。

时间复杂度也算$O(N)$吧，276ms仅供参考，似乎是比其他方法都快点。

```python []
class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        s = sum(nums)
        k = s % 3
        if not k:  
            return s
        a, b, hq = s, [-s, -s], heapq.heappushpop
        c, d = (1, 2) if k == 1 else (2, 1)
        for i in nums:
            if i % 3 == c:
                a = min(a, i)
            elif i % 3 == d:
                hq(b, -i)
        return s - min(a, -sum(b))
```
