思路：
当前的字符串中“1”出现的次数用 one 表示，它的最佳解为 t 次。
在末尾新添加一个字符时，
如果该字符为“1”，出现“1”的次数为 one+1，最佳解不变仍为 t 次。
如果该字符为“0”，出现“1”的次数不变仍为 one，最佳解有两种情况：
1）将末尾“0”转为“1”，则共需要 t+1 次；
2）末尾“0”不变，将字符串中的“1”全部转为“0”，则共需要 one 次。
取两种情况的最小值，即 min(one, t + 1)。

python代码如下：
```
class Solution:
    def minFlipsMonoIncr(self, S: str) -> int:
        t, one = 0, 0
        for c in S:
            t, one = (t, one + 1) if c == '1' else (min(one, t + 1), one)
        return t
```
