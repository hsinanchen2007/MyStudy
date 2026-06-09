## 思路

题目要求“连续子串”，我们考虑使用滑动窗口。 这是常规的滑动窗口题目，并且是一个可变窗口类型。

### 可变窗口大小

对于可变窗口，我们同样固定初始化左右指针 l 和 r，分别表示的窗口的左右顶点。后面有所不同，我们需要保证：

1. l 和 r 都初始化为 0
2. r 指针移动一步
4. 判断窗口内的连续元素是否满足题目限定的条件
   - 4.1 如果满足，再判断是否需要更新最优解，如果需要则更新最优解。并尝试通过移动 l 指针缩小窗口大小。循环执行 4.1
   - 4.2 如果不满足，则继续。

形象地来看的话，就是 r 指针不停向右移动，l 指针仅仅在窗口满足条件之后才会移动，起到窗口收缩的效果。

![](https://pic.leetcode-cn.com/a3eb8146fc5131a7ab669652b41f88edff22e13bf608cc0cd6cb673c19bc68a8.jpg)



## 代码

```python

class Solution:
    def countChrs(self, w):
        res = [0]*26
        for c in w:
            res[ord(c)-ord('a')] += 1
        return res

    def findAnagrams(self, s: str, p: str) -> List[int]:
        if not s or not p:
            return []
        res = []
        n = len(p)
        target = self.countChrs(p)
        i = 0
        window = [0] * 26
        while i < n and i < len(s):
            window[ord(s[i]) - ord('a')] += 1
            i += 1
        i = 0
        j = n

        while i < len(s) - n + 1:
            if target == window:
                res.append(i)
            if j < len(s):
                window[ord(s[j]) - ord('a')] += 1
            window[ord(s[i]) - ord('a')] -= 1
            i += 1
            j += 1
        return res
```

**复杂度分析**
- 时间复杂度：$O(S * P)$
- 空间复杂度：$O(S * P)$

更多题解可以访问我的LeetCode题解仓库：https://github.com/azl397985856/leetcode  。 目前已经接近30K star啦。

大家也可以关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
