### 解题思路
根据数学逻辑，在末尾加1，遇到10则进1。
下边两个写法思路相同。

### 代码


#### 写法一，end记录当前位，从后向前遍历检查每一位

```python []
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        end = len(digits) - 1
        digits[end] += 1
        while digits[end] > 9:
            digits[end] = 0
            if end == 0:
                digits.insert(0, 1)
                break
            else:
                end -= 1
                digits[end] += 1
        return digits
```

#### 写法二，for循环遍历

```python []
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        # 先在末位+1
        digits[-1] += 1
        # 循环遍历检查是否需要进一
        for i in range(len(digits))[::-1]:
            if digits[i] > 9:
                digits[i] = 0
                if i == 0:
                    digits.insert(0, 1)
                else:
                    digits[i - 1] += 1
        return digits
```