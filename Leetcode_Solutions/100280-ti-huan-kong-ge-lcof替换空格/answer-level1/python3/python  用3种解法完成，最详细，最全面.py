### 解题思路
调用replace函数就可以完成字符串的替换，代码如下：
### 代码

```python3
class Solution:
    def replaceSpace(self, s: str) -> str:
       
        s = s.replace(' ','%20')
        return s
```

第二种：创建一个新的空字符串，并对原来的字符串进行遍历
代码如下：

```python
 class Solution:
    def replaceSpace(self, s: str) -> str:
        s1 = ''
        for c in s:
            if c == ' ':
                s1 += '%20'
            else:
                s1 += c
        return s
```
第三种：在第二种的基础上改进，字符串为不可变类型，每加一个字符就会成为一个新的字符串，方法二太耗内存
此方法用列表来完成对新字符串的储存，最后再用join函数将列表转化为字符串。（从而避免产生多个字符串浪费内存）

```python
class Solution:
    def replaceSpace(self, s: str) -> str:
        s1 = []                       
        for c in s:                  
            if c == ' ':            
                s1.append('%20')        
            else:                       
                s1.append(c)
        return ''.join(s1)              
```