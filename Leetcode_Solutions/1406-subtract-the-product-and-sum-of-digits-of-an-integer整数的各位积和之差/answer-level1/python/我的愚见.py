### 解题思路
我相信肯定会有更好的解法，但我第一时间想到的是这个解法：首先，将数字先转换成字符串，通过map方法将字符串中的每个字符转化为Int,然后全转化为列表的元素，求和可以用列表内置的sum函数，如何求积可以通过循环遍历列表中的每一个元素，并定义一个变量，把每次遍历的累积存储下来，最后作差得出解法

### 代码

```python
class Solution(object):
    def subtractProductAndSum(self, n):
        cut = 1
        new = list(map(int,str(n)))
        for i in range(0,len(new)):
            cut *=new[i]
        return cut - sum(new)
        
    
```