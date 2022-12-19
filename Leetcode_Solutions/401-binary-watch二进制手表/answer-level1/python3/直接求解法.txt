这题的关键在于, 给定m位的序列, 从这m位当中选择n位置为1,其余的m-n位置为0, 求可能的二进制数组合.
也即 [make combinations size k](https://www.***.org/make-combinations-size-k/) 问题的变体.关于该问题的代码如下
```python
def _num_gen(n,m,rv,left=0,temp=0):
    if n == 0:
        if (m==4 and temp < 12) or (m==6 and temp < 60) :
            rv.append(temp)
        return
    for i in range(left, m):
        temp += 2**i
        _num_gen(n-1, m, rv, i + 1, temp)
        temp -= 2**i
```
其中需要注意的是, `temp` 当生成小时的数字时, 改数字不能大于12, 当生成分钟的数字时该数字不能大于60
关于该题的所有代码如下
```python
class Solution:
    def readBinaryWatch(self, num: int) -> List[str]:
        rv = []
        def _num_gen(n,m,rv,left=0,temp=0):
            if n == 0:
                if (m==4 and temp < 12) or (m==6 and temp < 60) :
                    rv.append(temp)
                return
            for i in range(left, m):
                temp += 2**i
                _num_gen(n-1, m, rv, i + 1, temp)
                temp -= 2**i
        def _helper(hours, minutes):
            rv = []
            hour_list = []
            _num_gen(hours, 4, hour_list)
            minute_list =[]
            _num_gen(minutes, 6, minute_list)
            for i in hour_list:
                for j in minute_list:
                    s = "{}:{:02d}".format(i,j)
                    rv.append(s)
            return rv
        for hour_point in range(min(num, 4)+1):
            minute_point = num-hour_point
            rv.extend(_helper(hour_point, minute_point))
        return rv
```

