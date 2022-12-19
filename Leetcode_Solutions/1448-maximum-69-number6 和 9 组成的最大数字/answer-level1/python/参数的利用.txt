### 解题思路
这道题我用的是字符串的内置函数replace里面的特性进行转换的，先遍历每个字符，如果遇到6且是第一次就将6换成9，如果是9的话，就跳出本次循环，进入下一循环逐一判断

### 代码

```python
class Solution(object):
    def maximum69Number (self, num):
        dight = str(num)
        for i in range(0,len(dight)):
            if dight[i] == '6':
                num = int(dight.replace(dight[i],'9',1))
            else:
                continue  
        return num
```