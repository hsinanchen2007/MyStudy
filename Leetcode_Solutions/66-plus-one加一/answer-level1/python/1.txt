### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if digits[len(digits) - 1]<=8:
            digits[len(digits) - 1]=digits[len(digits) - 1]+1
            return digits


        i=len(digits)-1
        while(i>=0):
            if i==0 and digits[i]==9:
                digits.append(0)
                digits[0]=1
                for j in range(1,len(digits)-1):
                    digits[j]=0
                return digits
            if digits[i]==9:
                digits[i]=0
            else:
                digits[i]=digits[i]+1
                return digits

            i=i-1
```