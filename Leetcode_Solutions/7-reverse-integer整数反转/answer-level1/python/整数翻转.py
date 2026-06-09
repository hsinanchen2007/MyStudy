第一次尝试写了很长，用时48ms，参考了题目解答
发现正则法、除10取余法、字符串法
认为正则法完全不需要，正则的代码块完全没有用
乘除代码消耗太贵了
所以比较好的字符串法
最后的结果是40ms

```
class Solution:
    def reverse(self, x: int) -> int:
        strx = str(x)
        if strx[0] == '-':
            strx = list(strx[1:])
            strx.append('-')
        else:
            strx = list(strx)
        strx.reverse()        #list才会有翻转reverse()的属性，字符串是不能翻转的，也可以用for循环翻转
        strx = ''.join(strx)            
        result = int(strx)        #这里的strx需要是一个字符串类型的，不能是list数组形式的
        result = result if result >= (-2**31) and result <= (2**31-1) else 0
        return result
```
