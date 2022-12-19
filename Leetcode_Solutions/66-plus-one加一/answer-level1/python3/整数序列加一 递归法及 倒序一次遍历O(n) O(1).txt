### 解题思路
递归的写法

### 代码

```python3
class Solution:
    def fun(self, num):
        return (num + 1) % 10
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits == []: # 递归进位到最前情况
            return [1]
        m = len(digits) - 1
        digits[m] = (digits[m] + 1) % 10
        # digits[m]为0 进位
        if not digits[m]:
            digits[:m] = self.plusOne(digits[:m])
        return digits
        
        
```

### 解题思路
仅一次遍历时间复杂度O(n)的写法：加后temp不为零则终止, 为零则从后往前进位， 


```python3
class Solution:
    def fun(self, num):
        return (num + 1) % 10
    def plusOne(self, digits: List[int]) -> List[int]:
        index = len(digits) - 1
        digits[index] = temp = (digits[index] + 1) % 10
        while not temp: # temp为零需进位
            if index == 0: # index 已经在首位了还需进位
                digits.insert(0, 1)
                break
            else:
                index -= 1
                digits[index] = temp = (digits[index] + 1) % 10
        return digits
        
        
```