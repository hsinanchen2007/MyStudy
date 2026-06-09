### 解题思路
      该题有两种思路：
              1.将整数转化成字符串，在                 将字符串转化成列表，反                 转即可
              2.用数学的方法，通过对x                  取余取模，达到反转的目的
      注意：
            在python中并不需要考虑整数             溢出的问题，所以大可不必在              反转过程中判断是否溢出，只              需在最后判断是否超出范围即可

### 代码
    下列是第一种方法的实现，效率较高，鲁棒性较强
```python3
class Solution:
    def reverse(self, x: int) -> int:
        if x<0:
            x=-x
            x_list=list(str(x))
            x_list.reverse()
            x=int("".join(x_list))
            return 0 if -x<=-2147483648 else -x
        else:#x大于0
            x_list=list(str(x))
            x_list.reverse()
            x=int("".join(x_list))
            return 0 if x>=2147483647  else x
```