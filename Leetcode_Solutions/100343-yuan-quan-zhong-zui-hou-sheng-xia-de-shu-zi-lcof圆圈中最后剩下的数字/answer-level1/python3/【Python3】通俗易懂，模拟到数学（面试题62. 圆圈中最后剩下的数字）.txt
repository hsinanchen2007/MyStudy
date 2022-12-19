
# 模拟
## 思路
由题目可知，每次删除一个元素之后，我们需要从下一个元素重新编号，并且我们的编号是成环的。 由“成环”这句话，我想到了使用模运算。

算法如下：

- 初始化一个0，1，。。。 n - 1的数组用来模拟。 并初始化起点为0，size为n
- 删除元素。我们数组大小不断减去1，并且我们重新规划start和size， start = i，size -= 1
- 删除元素的根据就是`(m + start - 1) % size`
- 不断循环，直到size变为1，返回nums剩下的最后一个元素即可。

## 代码

```python
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        nums, size, start = [i for i in range(n)], n, 0
        while size != 1:
            i = (m + start - 1) % size
            nums.pop(i)
            start = i
            size -= 1
        return nums.pop()
```


**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$


# 数学分析

## 思路

使用数学法可以在$O(1)$的空间解决。

## 代码

```python
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        ans = 0
        for size in range(2, n + 1):
            ans = (ans + m) % size
        return ans
```


**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
