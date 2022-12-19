
LeetCode直接把递推公式告诉你的题目真的不多见，大家珍惜～

## 暴力
首先我们使用最暴力的解法，直接模拟题目描述。

```python
class Solution:
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        return (self.fib(n - 1) + self.fib(n - 2)) % 1000000007
```

## 暴力 + hashmap

这种解法没有栈溢出，但是超时了，我们考虑使用hashmap来优化。

> 如果栈溢出的话，就没必要hashmap优化了。由于不同语言最大栈深度不同，而JS（V8引擎）相对于Python来说栈会更大一点

```python
class Solution:
    visited = dict()
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n in self.visited:
            return self.visited[n]
        self.visited[n] = (self.fib(n - 1) + self.fib(n - 2)) % 1000000007
        return self.visited[n]
```

## 迭代

```python
class Solution:
    def fib(self, n: int) -> int:
        a, b = 0, 1
        for _ in range(n):
            a, b = b, a + b
        return a % 1000000007
```
欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/960f0fcedb710cca012ce919c8cd275be29ce72312da2da095b0eb13b99ec60f.jpg)