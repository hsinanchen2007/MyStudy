### 解题思路
两种情况：
- 9999型
- 普通数字型
> `return [int(i) for i in str(pow(10,len(digits)))]` 具有通用意义，将数字转化为数组

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        for i in range(len(digits)-1,-1,-1):
            digits[i] += 1
            digits[i] %= 10
            if digits[i] != 0:
                return digits
        return [int(i) for i in str(pow(10,len(digits)))]
```