## 思路

由于丑数是质因数只有2，3，5的数（1除外）。 因此丑数可以定义为2^x * 3 ^ y * 5 ^ z。  


我们定义三种状态：

- 最后一个乘的质因数是2
- 最后一个乘的质因数是3
- 最后一个乘的质因数是5

为了简单起见，我们定义三个指针，分别指向上一个`乘的质因数是2`, `乘的质因数是3`, `乘的质因数是5`的位置。

## 代码

```python
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        states = [1] * n
        p1 = p2 = p3 = 0

        for i in range(1, n):
            states[i] = ith =  min(states[p1] * 2, states[p2] * 3, states[p3] * 5)
            if ith == states[p1] * 2: p1 += 1
            if ith == states[p2] * 3: p2 += 1
            if ith == states[p3] * 5: p3 += 1
        return states[-1]

```


**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
