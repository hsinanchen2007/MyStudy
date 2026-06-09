### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        nums=0
        for i in range (1,len(digits)+1):
            if digits[-i]+1!=10:
                return digits[:-i]+[digits[-i]+1]+[0]*nums
            nums+=1
        return [1]+[0]*len(digits)

```