### 解题思路 
这个方法是在pat那边想过来的，就是利用python3字符串视为列表的特型，把数据类型换成字符串反向读取，然后利用int过滤一遍前零(lstrip的方法还并没有试过)，用一个end变量标注正负性，最后判断溢出并输出

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        end=""
        if(x<0):
            end="-"
            x=-x
        c=int(str(x)[::-1])
        if(c>2**31-1 or c<2**31*(-1)):
            return 0
        else:
            return end+str(c)
```