```python
class MyCalendarThree(object):

    def __init__(self):
        self.exists = []

    def book(self, start, end):
        """
        :type start: int
        :type end: int
        :rtype: int
        """
        m = 0
        self.exists.extend([[start, 1] ,[end, -1]])
        self.exists.sort()
        ret = 0
        for _, v in self.exists:
            ret += v
            if ret > m:
                m = ret
        return m
```
