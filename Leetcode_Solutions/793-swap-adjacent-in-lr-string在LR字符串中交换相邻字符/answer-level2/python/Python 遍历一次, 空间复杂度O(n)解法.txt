首先设定2个变量
```python
L = R = 0
```
表示当前未配对的`L` 和 `R`的个数

同时遍历两个字符串, 记录当前位置对应的字符`s, e`.
只需要考虑当前位置字符是`L`和`R`的情况

首先, 如果`s == 'R'`, 即当前位置`start`字符串字符为`R`.
如果`L !=0 `, 说明在`end` 字符串前有未配对的`L`,注意在`start`, `L`可以向左(低索引处)移动,`R`向右移动,但是两者相遇后不能继续移动,当前`s=='R'`, 需要从`start`字符串当前索引的右侧,寻找到一个`L`移动到当前索引的左侧, 肯定不成立, 返回`False`
对于其他情况, 记录当前有一个`R`需要配对 即` R += 1 `

然后判断如果`e == R`,即当前`end`字符串的字符为`R`
如果` L!=0 `, 和上面的思路一样, 返回`False`
对于其他情况, 把需要配对的`R`减一, 说明已经配成了一对

我们按照这个顺序, 如果`s == e == 'R'`,按照上面的判断顺序, 也是可以返回正确结果的,即 先加1后减1

对于`L`, 同理我们需要先判断`end` 加一, 再判断`start` 进行减一操作


代码如下

```python
class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        n = len(start)
        L = R = 0
        for i in range(n):
            s, e = start[i], end[i]
            if s == 'R':
                if L != 0:
                    return False
                else:
                    R += 1
            if e == 'R':
                if R == 0 or L != 0:
                    return False
                else:
                    R -= 1
            if e == 'L':
                if R != 0:
                    return False
                else:
                    L += 1

            if s == 'L':
                if L == 0 or R != 0:
                    return False
                else:
                    L -= 1
        return L == 0 and R == 0
```