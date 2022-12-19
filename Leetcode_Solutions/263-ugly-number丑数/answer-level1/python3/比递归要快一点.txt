## 成绩（2019.6.7）
执行用时 : 48 ms, 在Ugly Number的Python3提交中击败了96.44% 的用户

内存消耗 : 13 MB, 在Ugly Number的Python3提交中击败了98.81% 的用户

## 思路
不停地除去2 3 5，直到不能整除，最后的余数如果是1，则是丑数，如果不是1，则不是丑数

例外情况：0，因为0可以被任何数整除，所以不设置限制会死循环

评论区中有用递归的做法，递归很漂亮，但是对于特别大的数，比如$2^n$使用递归会额外增加$n$的时间复杂度，因为每次调用函数都会造成常数的时间花费。所以这样写一个函数，只调用三次，个人感觉会比较经济
## 代码

```python
 class Solution:
    def isUgly(self, num: int) -> bool:
        if num == 0:
            return False
        def divide(num, n):
            while num%n == 0:
                num //= n
            return num
                
        num = divide(num, 2)
        num = divide(num, 3)
        num = divide(num, 5)
        if num == 1:
            return True
        else:
            return False
```
