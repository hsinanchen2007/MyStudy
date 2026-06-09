### 解题思路
关于 bitmap [bitMap原理](https://www.jianshu.com/p/bf9dbbc147ed) 在编程珠玑上提过此用法。
之前在某一道题的题解上提过此，排序 10 万个整数，使用外部排序（归并排序） 或者 bitmap 。

[41. 缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/) 使用 bitmap


这里代码还是挺好写的，就是位运算要熟悉熟悉。然后要想到此。
本质上 bitmap 是一个只取 0-1 值的 hash 表，计数数组。


### 代码

```python3
class Solution:
    def isUnique(self, astr: str) -> bool:

        mask = 0
        for x in astr:
            move_bit = ord(x)-ord('a')
            if (mask & (1<<move_bit)) != 0: # (这里不是 == 1, 而是不等于 0，还可以为2,3，其他值)
                return False
            else:
                mask = mask | (1<<(ord(x)-ord('a')))
        return True

```
### 原来的代码
``` python3  
class Solution:
    def isUnique(self, astr: str) -> bool:

        return len(set(astr)) == len(astr)
```