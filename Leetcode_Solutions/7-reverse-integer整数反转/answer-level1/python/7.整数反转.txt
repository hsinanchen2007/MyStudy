### 解题思路
由整数反转--->字符串反转
方法一：切片法反转
执行用时 :24 ms
内存消耗 :12.7 MB

方法二：使用reserved()方法
执行用时 :28 ms
内存消耗 :12.7 MB
### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        #转换成字符串，整数反转->字符串反转
        #方法一：切片法反转y[::-1]
        '''
        if(x >= 0):                 #处理正整数
            y = str(x)              #str()把x转成字符串 
            y = int(y[::-1])
        else:                       #处理负整数
            y = str(abs(x))         #把负整数取绝对值之后再反转，最后添加负号
            y = int(y[::-1])  
            y = -y
        
        '''


        #方法二：reversed()反转
        if(x >= 0):                 #处理正整数
            y = str(x)              #str()把x转成字符串 
            y = int(''.join(reversed(y)))
        else:                       #处理负整数
            y = str(abs(x))         #把负整数取绝对值之后再反转，最后添加负号
            y = int(''.join(reversed(y)))  
            y = -y
        

        if(y < (-2)**31) or (y > 2**31-1):   #如果超出 [−2^31,2^31−1]范围，返回0
            return 0
        return y
```