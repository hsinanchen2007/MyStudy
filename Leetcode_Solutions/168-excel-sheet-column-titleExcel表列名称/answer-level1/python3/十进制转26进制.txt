## 思路

做这道题要先了解一下, 十进制转二进制, 比如 `6` 转 成二进制多少?

```
 2 |_ 6 _                       ^
    2|_ 3 _  ······ 0    |
     2|_ 1 _ ·······1    |
       |_ 0_ ·······1    |
 	
```

所以， 我们能得到二进制为 `110`, 这道题换句话说是十进制转`26`进制的

但是有个难点:  如果 `26` 转成 字母是多少?

```
 26|_ 26 _
        1   ··· 0
```

这里出现了`0`, 但是我们`26` 字母 没有任何一个字母是表示`0`, 所以我们可以从 商 借一个给余数

```
  26| _ 26 _
  	0 ··· 26
```

这样就可以表示出来了,所以代码如下

```python
class Solution:
    def convertToTitle(self, n: int) -> str:
        res = ""
        while n:
            n, y = divmod(n, 26) 
            if y == 0:
                n -= 1
                y = 26
            res = chr(y + 64) + res
        return res
```

看了其他做法, 他们先让`n` 减一

```python
class Solution:
    def convertToTitle(self, n: int) -> str:
        res = ""
        while n:
            n -= 1
            n, y = divmod(n, 26) 
            res = chr(y + 65) + res
        return res
```

还有一种递归写法:

```python
class Solution:
    def convertToTitle(self, n: int) -> str:
        return "" if n == 0 else self.convertToTitle((n - 1) // 26) + chr((n - 1) % 26 + 65)
```

