### 解题思路
此题的关键点是处理末位是9的情况。python结题思路是 数据类型转换 将list 转换为 str，再转换为 int，执行加一，在换回 list 输出。

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        s = ""
        for i in digits:
            s += ''.join(str(i))
        plus = list(str(int(s)+1))
        return plus
```