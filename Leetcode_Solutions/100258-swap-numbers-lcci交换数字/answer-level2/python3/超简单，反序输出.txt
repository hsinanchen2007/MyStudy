### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def swapNumbers(self, numbers: List[int]) -> List[int]:
        numbers_new =[]
        for i in range((len(numbers)-1),-1,-1):
            numbers_new.append(numbers[i])
        return numbers_new
```