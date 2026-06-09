### 解题
这道题采用了取巧的方法将数字转成了字符串，通过循环字符串下标字符串下标就可以得到每个数字，最终获得想要结果。改进之处有是将字符的类型转换

### 代码

```python3
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        strNum=str(n)
        ji=0
        he=0
        for i in range(0,len(strNum)):
            if i==0:
                ji=int(strNum[i])
            else:
                ji=ji*int(strNum[i])
            he=he+int(strNum[i])
        return ji-he

```