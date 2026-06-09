
> 实际上int(res) 部分可以改成迭代运算，只是为了方便看清主脉络，省略了。


## 思路


- 如果是+或者是-，并且是第一位，我们认为是合法的。
- 剩下的迭代，只有在 ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]中，我们才认为合法
- 最后如果res是+或者-，说明本身不合法，我们返回0。 否则我们迭代一次求出整数。这里为了简单直接使用了int函数


## 代码

```python
class Solution:
    def strToInt(self, s: str) -> int:
        cs = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]
        res = ""
        s =  s.strip()
        for i in range(len(s)):
            c = s[i]
            if (c == '+' or c == '-') and i == 0:
                res += c
                continue
            if c not in cs: break
            res += c
        if res == '+' or res == '-': return 0
        return max(-2**31, int(res or 0)) if int(res or 0) < 0 else min(2**31 - 1, int(res or 0))
```



**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：我们使用了res，因此空间复杂度为 $O(N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
