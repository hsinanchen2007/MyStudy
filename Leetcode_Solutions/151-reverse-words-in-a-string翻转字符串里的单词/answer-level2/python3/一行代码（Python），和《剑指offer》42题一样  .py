```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(list(filter(lambda a: a.strip(), s.strip().split(" ")))[::-1])
```


甚至可以更短：

```python
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(s.strip().split()[::-1])

```

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/960f0fcedb710cca012ce919c8cd275be29ce72312da2da095b0eb13b99ec60f.jpg)





