**思路：**

对于熟悉括号匹配的同学来说，迅速想到解法并不难。括号匹配用到栈结构，遇到左括号`(`入栈，遇到右括号`)`出栈，栈的深度就是当前括号的深度。想要把括号字符串分为两个序列，并让他们的最大深度尽量小，那么我们只需要开两个栈，在入栈的过程中，尽量保持两个栈的深度相等即可，需要点技巧的地方在于入栈时候记录一下进入的是哪个栈，当然也可以用一个元素带标记的栈来实现。

如果深入分析括号位置的奇偶性，我们还可以总结出更简单的规则：我们观察一下字符串`"(((())))"`，先是一段连续的入栈，那么根据我们的入栈原则，肯定是奇数位置进入栈`1`，偶数位置进入栈`2`，那么当字符串不是连续入栈的情况呢？答案是每出栈一次就改变了一次入栈的奇偶性，如果入栈次序是`1-2-1-2`，这时有一个出栈，那么下一次出栈的顺序就倒过来从`2`开始出，同时也改变入栈奇偶性，下一次入栈就从`2`入，如果连续两个出栈，那么奇偶性就不变，下次入栈继续从`1`入。这样，利用按位与判断位置的奇偶性，用字符是否为`(`判断入栈的奇偶性是否改变，两者进行异或操作就得到了答案。


**代码：**
```python
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        flg = []
        s1 = []
        s2 = []
        ans = []
        for c in seq:
            if c == '(':
                if len(s1) <= len(s2):
                    s1.append(c)
                    ans.append(0)
                    flg.append(0)
                else:
                    s2.append(c)
                    ans.append(1)
                    flg.append(1)
            else:
                f = flg.pop()
                if f == 0:
                    ans.append(0)
                    s1.pop()
                else:
                    ans.append(1)
                    s2.pop()
        return ans
```

```python
# 一行写法 by lee215
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        return [i & 1 ^ (c == '(') for i, c in enumerate(seq)]
```