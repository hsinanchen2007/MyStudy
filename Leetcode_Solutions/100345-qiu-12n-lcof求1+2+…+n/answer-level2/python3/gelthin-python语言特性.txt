### 解题思路
python 语言的特性 逻辑表达式 很多项的结果，不是返回 True or False

而是一些其他的特性 [64. Python基础你确定你知道吗？](https://leetcode-cn.com/problems/qiu-12n-lcof/solution/64-pythonji-chu-ni-que-ding-ni-zhi-dao-ma-by-lulla/)
参见 [一行 Python](https://leetcode-cn.com/problems/qiu-12n-lcof/solution/yi-xing-python-by-chinayiqun/)
也可以用 [try catch](https://leetcode-cn.com/problems/qiu-12n-lcof/solution/bu-huo-yi-chang-by-ltcccc/)



### 代码

```python3
class Solution:
    def sumNums(self, n: int) -> int:
        ## 递归：
        return n and n+self.sumNums(n-1)
```