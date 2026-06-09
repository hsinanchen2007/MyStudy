
```python []
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        result = 0
        # 将数组转化为整数
        for i in range(len(digits)):
            result = result * 10 + digits[i] 
        # 整数+1
        result += 1
        # 将整数转化为字符列表
        result = list(str(result))
        # 对列表中每个字符整数化
        return [int(i) for i in result]
```


