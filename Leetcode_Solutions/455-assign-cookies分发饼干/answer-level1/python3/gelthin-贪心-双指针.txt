### 解题思路
这里进行排序后即可处理。
一般来说，贪心思路都需要用到排序，不然的话，无法贪心。

然后同时遍历两个数组，实际上与题目[392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/) 解法一致。
参看评论区[别人代码](https://leetcode-cn.com/problems/assign-cookies/comments/8929)
有一个细节，就是 result 和 a 可以共用，即最后可以直接返回 a.

### 代码

```python3
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        m, n = len(g), len(s)
        a, b = 0, 0
        result = 0
        while (a<m) and (b<n):
            if g[a] <= s[b]:
                result += 1  # result 和 a 可以共用
                a += 1
            b += 1
        return result
```