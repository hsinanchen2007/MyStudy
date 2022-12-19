特殊test case需要考虑： 比如 506，06是不合法的。 因此这种情况总共只有1种


```python
class Solution:
    cnt = 0
    def translateNum(self, num: int) -> int:
        s = str(num)
        n = len(s)
        self.cnt = 0
        def backtrack(start):
            if start >= n: 
                self.cnt += 1
                return
            # 06不合法
            if start < n - 1 and s[start] != "0" and int(s[start:start + 2]) <= 25:
                backtrack(start + 2)
            backtrack(start + 1)
        backtrack(0)
        return self.cnt
```


**复杂度分析**
- 时间复杂度：$O(2^N)$
- 空间复杂度：$O(2^N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
