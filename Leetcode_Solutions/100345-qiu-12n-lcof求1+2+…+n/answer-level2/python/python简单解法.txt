一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
短路思想感觉太偏了，工程上可以用try catch

### 代码

```python
def sum(n):
    try:
        1 % n
        return n + sum(n-1)
    except:
        return 0

class Solution(object):
    def sumNums(self, n):
        return sum(n)
```