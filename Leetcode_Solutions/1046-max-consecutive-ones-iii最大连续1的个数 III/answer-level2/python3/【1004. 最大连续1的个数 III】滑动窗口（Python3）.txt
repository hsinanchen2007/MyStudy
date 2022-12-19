## 思路

如果题目没有`最多可以将 K 个值从 0 变成 1 。`这个条件，那么会很简单，是一个常规的滑动窗口模板题。 我们加上这个条件对问题有什么样的影响呢？

开始之前，我来简单介绍下可变滑动窗口的解题套路

## 可变窗口解题套路

对于可变窗口，我们同样固定初始化左右指针 l 和 r，分别表示的窗口的左右顶点。后面有所不同，我们需要保证：

1. l 和 r 都初始化为 0
2. r 指针移动一步
4. 判断窗口内的连续元素是否满足题目限定的条件
   - 4.1 如果满足，再判断是否需要更新最优解，如果需要则更新最优解。并尝试通过移动 l 指针缩小窗口大小。循环执行 4.1
   - 4.2 如果不满足，则继续。

形象地来看的话，就是 r 指针不停向右移动，l 指针仅仅在窗口满足条件之后才会移动，起到窗口收缩的效果。

![](https://pic.leetcode-cn.com/93f3a975c4b94bb9ddf8956e3f642cb5ebcc25e3016a00545ab69834190d2363.jpg)

## 回到本题

我们继续回到刚才的思路。这道题和通用套路不同的是，我们只需要记录下加入窗口的是0还是1：

- 如果是1，我们什么都不用做
- 如果是0，我们将K减1


相应地，我们需要记录移除窗口的是0还是1:

- 如果是1，我们什么都不做
- 如果是0，说明加进来的时候就是1，加进来的时候我们K 减去了1，这个时候我们再加1。

## 代码


```python
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        i = res = 0
        for j in range(len(A)):
            K -= 1 - A[j]
            if K < 0:
                while i < j and A[i] == 1:
                    i += 1
                i += 1
                K += 1
            res = max(res, j - i + 1)
        return res
```


甚至更简洁：

```python
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        i = 0

        for j in range(len(A)):
            K -= 1 - A[j]
            if K < 0:
                K += 1 - A[i]
                i += 1
        return j - i + 1
```

**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
