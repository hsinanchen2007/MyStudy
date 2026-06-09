### 解题思路
python,20ms,进位做法
其他做法，str int转换
#return [int(x) for x in str(int(''.join([str(i) for i in digits])) + 1)]

### 代码

```python
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        jin=0
        for i in range(len(digits)-1,-1,-1):
            if jin==1 :
                digits[i]+=1
            elif i==len(digits)-1:
                digits[i]+=1
            if digits[i]==10:
                digits[i]=0
                jin=1
            else:
                jin=0
        if digits[0]==0:
            digits.insert(0,1)
        return digits
            
```