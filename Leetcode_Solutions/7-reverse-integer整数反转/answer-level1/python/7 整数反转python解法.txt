### 解题思路
[5::-1] 表示的是5，4，3，2，1，0
[5:0:-1] 表示的是5，4，3，2，1
[5:1:-1] 表示的是5，4，3，2
注意先转换成str，去翻转。然后取反即可。

### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """

        if -10 < x < 10:
            return x
        
        str_x = str(x)
        len_x = len(str_x)
        if str_x[0] == '-':
            if str_x[len_x-1] == '0':
                str_x = str_x[0] + str_x[len_x-2:0:-1] 
            else:
                str_x = str_x[0] + str_x[len_x-1:0:-1] 
        else:
            if str_x[len_x-1] == '0':
                str_x = str_x[len_x-2::-1] 
            else:
                str_x = str_x[len_x-1::-1] 
        
        x = int(str_x)
        return x if -2147483648 < x < 2147483647 else 0


```