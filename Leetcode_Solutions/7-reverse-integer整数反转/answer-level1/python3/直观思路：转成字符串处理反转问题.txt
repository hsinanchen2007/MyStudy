### 解题思路
将int型的整数转成字符串处理，但是要注意：1.正负数字的不同对待；2.判断最后结果是否超出32位范围。
详细操作见代码注释。

### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        temp=list(str(x))#数字转为字符串列表
        if x<0:          #负数情况要注意处理'-' 
            temp.remove('-')
            temp.reverse()
            r=''.join(temp)#组合为新的字符串
            r= -int(r)     #转为整型加'-'
        else:              #正数情况直接反转
            temp.reverse()
            r=''.join(temp)
            r= int(r)
        if not -pow(2,31)<=r<=pow(2,31)-1:
            #记住pow表示乘方的语法
            return 0
        else:
            return r
```