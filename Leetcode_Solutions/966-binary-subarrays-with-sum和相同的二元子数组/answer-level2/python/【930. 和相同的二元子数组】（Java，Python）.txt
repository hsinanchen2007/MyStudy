
## 思路


由于数组仅包含 0  和 1， 那么问题可以转化为`给定一个0，1数组，你可以选择S个1和任意个0，你可以有多少选择？`

而上述问题可以转化为`给定一个0，1数组，你可以选择最多S个1和任意个0，你的选择数`减去 `给定一个0，1数组，你可以选择最多S - 1个1和任意个0，你的选择数`。

最多xxxx 这种可以使用可变滑动窗口模板解决。

这里插播下可变滑动窗口的思路

### 可变窗口大小

对于可变窗口，我们同样固定初始化左右指针 l 和 r，分别表示的窗口的左右顶点。后面有所不同，我们需要保证：

1. l 和 r 都初始化为 0
2. r 指针移动一步
4. 判断窗口内的连续元素是否满足题目限定的条件
   - 4.1 如果满足，再判断是否需要更新最优解，如果需要则更新最优解。并尝试通过移动 l 指针缩小窗口大小。循环执行 4.1
   - 4.2 如果不满足，则继续。

形象地来看的话，就是 r 指针不停向右移动，l 指针仅仅在窗口满足条件之后才会移动，起到窗口收缩的效果。

![](https://pic.leetcode-cn.com/9ae2ceeb33d6d263245d518c919d71f5f9fa0a960654c00e0894fc481e633e72.jpg)

## 代码

```python
class Solution:
    def numSubarraysWithSum(self, A: List[int], S: int) -> int:
        def atMostK(A, S):
            if S < 0:
                return 0
            i = res = 0

            for j in range(len(A)):
                S -= A[j]
                while S < 0:
                    S += A[i]
                    i += 1
                res += j - i + 1
            return res
        return atMostK(A, S) - atMostK(A, S - 1)
```


```java
class Solution {
    public int atMost(int[] A, int S) {
        if (S < 0) return 0;
        int res = 0, i = 0, n = A.length;
        for (int j = 0; j < n; j++) {
            S -= A[j];
            while (S < 0)
                S += A[i++];
            res += j - i + 1;
        }
        return res;
    }
    public int numSubarraysWithSum(int[] A, int S) {
        return atMost(A, S) - atMost(A, S - 1);
    }
}
```

**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)