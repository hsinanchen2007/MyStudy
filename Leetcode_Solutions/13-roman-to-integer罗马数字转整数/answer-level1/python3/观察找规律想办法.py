### 解题思路
例:MCDLXXV
是肯定有一个指针i,j=i+1来判断s[i,j+1]是否属于IV,IX,XL,XC,CD,CM之列。
我是使用的数值判断，大神是使用的element判断，给我提供了新的思路，非常棒。

### 我的代码

```
class Solution:
    def romanToInt(self, s) -> int:
        length = len(s)
        arr = [[1000, 'M'], [500, 'D'],[100, 'C'], [50, 'L'], [10, 'X'], [5, 'V'], [1, 'I'] ]
        len_arr = len(arr)

        result = 0
        i = 0
        m = 0
        while i < length:
            j = i + 1
            position_i = 0
            position_j = 0
            value_i = 0
            value_j = 0
            value_i_j = 0
            while m < len_arr:
                if s[i] == arr[m][1]:
                    value_i = arr[m][0]
                    position_i = m
                if j < length and s[j] == arr[m][1]:
                    value_j = arr[m][0]
                    position_j = m
                if ( value_i > 0 and value_j > 0 ) or ( value_i > 0 and j == length ):
                    m = min(position_i,position_j)
                    break
                m += 1

            if value_i >= value_j:
                i += 1
                result += value_i
            else:
                result += abs(value_i-value_j)
                i += 2

        return result

```


### 膜拜了一下大神的思路

```python3
class Solution:
    def romanToInt(self, s) -> int:
        d = {'I':1, 'IV':3, 'V':5, 'IX':8, 'X':10, 'XL':30, 'L':50, 'XC':80, 'C':100, 'CD':300, 'D':500, 'CM':800, 'M':1000}
        return sum(d.get(s[max(i-1, 0):i+1], d[n]) for i, n in enumerate(s))
```