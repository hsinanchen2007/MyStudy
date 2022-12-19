### 解题思路
此处撰写解题思路
转化为字符串类型再遍历就好了
### 代码

```python3
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        tem = 1
        sum = 0
        for i in str(n):
            tem *= int(i)
            sum += int(i)
        return tem - sum
```