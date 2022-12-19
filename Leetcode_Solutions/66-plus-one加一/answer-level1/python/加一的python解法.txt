### 解题思路
这道题刚开始没看懂什么意思 后来发现原来是直接遍历就可以 倒着遍历，是9变0，否则加1，直接返回即可

### 代码

```python
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        for i in range(len(digits)-1,-1,-1):
            if digits[i]!=9:
                digits[i]+=1
                return digits
            else:
                digits[i]=0
        digits.insert(0,1)
        return digits
```