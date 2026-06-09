### 解题思路
- 先对数组最后一个元素加1
- 数组反转，然后从前往后判断，出现10就置零，将下一位加一；
- 如果没有10了，提前结束；如果最后一位是10，则置零以后添加一个1在最后
- 数组再次反转，返回结果

### 代码

```python
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        digits[-1] += 1
        digits = digits[::-1]
        L = len(digits)
        for index,v in enumerate(digits):
            if index <= L-2 and v==10:
                digits[index]=0
                digits[index+1] +=1
            else:
                break
        if digits[-1]==10:
            digits[-1]=0
            digits.append(1)
        return digits[::-1]  
```