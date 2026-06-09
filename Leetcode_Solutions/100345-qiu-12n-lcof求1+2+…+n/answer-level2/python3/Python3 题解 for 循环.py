### 解题思路
1. 通过for  循环 ， range(0,n+1)
2. 应该还可以用递归实现。

### 代码

```python3
class Solution:
    def sumNums(self, n: int) -> int:
        sum = 0
        for i in range(0,n+1):
            sum+=i
        return (sum)
```
![屏幕快照 2020-02-14 22.14.24.png](https://pic.leetcode-cn.com/536be15da428fb63d1142b8df10014dc44c85b945dc0eda148b16edf4f1700b7-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-14%2022.14.24.png)
