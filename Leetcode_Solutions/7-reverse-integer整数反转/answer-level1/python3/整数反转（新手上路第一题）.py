### 解题思路
将整型转换成列表格式，利用reverse函数。
所以要分成正数和负数两种情况讨论(由于负数转成列表的时候，list[0]会存放'-'号)
再利用数位表示计算的方法即可。
最后需要对结果的范围进行判断。
（新手第一题，过程有点繁琐，望谅解）

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        sum1=0
        if x>0:
            x=list(str(x))
            x.reverse()
            for i in range(0,len(x)):
                sum1 += int(x[i])*(10**(len(x)-1-i))
        else:
            x=list(str(x))       
            x.remove(x[0]) 
            x.reverse()
            for i in range(0,len(x)):
                sum1 += int(x[i])*(10**(len(x)-1-i))
            sum1=-sum1
        
        if sum1>=-2**(31) and  sum1<=2**(31)-1:
            return sum1
        else:
            return 0

```