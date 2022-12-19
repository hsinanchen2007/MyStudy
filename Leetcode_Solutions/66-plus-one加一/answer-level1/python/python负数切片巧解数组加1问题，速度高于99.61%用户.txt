该题目主要需要考虑数组有几个9和9的位置的情况。
================================
循环中，切片倒叙遍历 判断当前位是否是9，如果不是，则直接将该位加1输出；  否则将改为置0，继续判断。  
但在这里要判断一下改为是否为数组首位，如果是则将该位置1，然后在appen一个0.

代码如下：
-------------------  
```python []
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        for i in range(len(digits)):
            if digits[-1 - i] == 9:
                digits[-1 - i] = 0
                if -1-i == -len(digits):
                    digits[-1 - i] = 1
                    digits.append(0)
                    return digits
            else:
                digits[-1 - i] += 1
                return digits