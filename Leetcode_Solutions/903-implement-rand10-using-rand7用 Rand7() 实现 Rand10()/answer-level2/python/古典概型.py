### 解题思路
如果字典枚举的多一点,时间效率更高

### 代码

```python
# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution(object):
    def rand10(self):
        """
        :rtype: int
        """
        #一个rand7()方法可以生成7到10
        dict7={
            (1,1):1,
            (1,2):2,
            (1,3):3,
            (1,4):4,
            (1,5):5,
            (1,6):6,
            (1,7):7,
            (2,1):8,
            (2,2):9,
            (2,3):10
        }
        while 1:
            a,b=rand7(),rand7()
            if (a,b) in dict7:
                return dict7[(a,b)]
```