### 解题思路
基本上描述为：
#### 大于0的32位整数（|a|<=2**32）：
转换为字符数组，进行数组的反转（reverse）,并通过join(list)和强制类型转换转换为整数，若依然是32位整数，则返回；
#### 小于0的32位整数：
对绝对值进行转换为字符数组，进行数组的反转，再转换为整数后若依然为32位整数，则返回整数的负值。

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        #int->str->int
        def splitstr(x):#split()对于"abc"不能转为['a','b','c'],故写一个函数分割字符串为字符数组
            res=[]
            for i in range(len(x)):
                res.append(x[i])
            return res
        if abs(x)>2**31:return 0
        if x>=0:
            y=splitstr(str(x))#[str(x).split()]
            y.reverse()#reverse()对可变量反转，需把字符串转为字符数组
            y=''.join(y)
            if abs(int(y))>2**31:return 0
        else:
            y=splitstr(str(abs(x)))#[str(abs(x)).split()]
            y.reverse()
            y=''.join(y)
            y='-'+y
            if abs(int(y))>2**31:return 0
        return int(y)
```