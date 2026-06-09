定义一个函数`f(digits)`，考虑以下情况：

1. 当末位不等于9的时候：直接返回末位+1之后的数组
```python
            if digits[-1] != 9:
                return digits[:-1] + [digits[-1]+1]
```

2. 当末尾等于9的时候，考虑两种情况：

第一种情况：如果前面还有数字，这时候相当于末尾由9变成0，然后对 digits[:-1] 执行加一操作，再将结果连起来，也就是返回：
```python
            return f(digits[:-1]) + [0]
```

第二种情况：前面已经没有数字了，这时候末尾还是由9变成0，然后再对 [0] 执行加一操作，再将结果连起来，也就是：
```python
            if not digits[:-1]:
                return f([0]) + [0]
```


最后完整代码如下：
```python
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """       
        def f(digits):
            if digits[-1] != 9:
                return digits[:-1] + [digits[-1]+1]
            
            if not digits[:-1]:
                return f([0]) + [0]
            return f(digits[:-1]) + [0]
        
        return f(digits)
```


提交结果：36ms，打败95.29%



