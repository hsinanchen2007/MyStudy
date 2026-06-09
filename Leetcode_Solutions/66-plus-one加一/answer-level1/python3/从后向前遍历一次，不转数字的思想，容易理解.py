### 解题思路
从后往前遍历一次，不利用转换数字的捷径思想

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        n=len(digits)

        for i in range(n-1,-1,-1):
            if digits[i]!=9:
                digits[i]+=1
                break
            else:
                digits[i]=0
                continue 
        if digits[0]==0:
            digits.append(0)
            digits[0]=1
        return digits
```