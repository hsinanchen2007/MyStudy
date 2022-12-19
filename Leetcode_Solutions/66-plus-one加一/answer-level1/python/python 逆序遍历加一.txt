### 解题思路
这道题需要注意的是最后一个元素加一之后是否需要进位即是否等于10，不需要的话就break返回，需要的话就往前遍历加一

### 代码

```python
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        if len(digits)==0:#边界条件判断
            return False
        addCarry=1
        for i in range(len(digits)-1,-1,-1):#往前遍历
            digits[i]+=addCarry
            if digits[i]==10:
                digits[i]=0
                if i==0:
                    digits.insert(0,1)
            else:
                break
        return digits
```