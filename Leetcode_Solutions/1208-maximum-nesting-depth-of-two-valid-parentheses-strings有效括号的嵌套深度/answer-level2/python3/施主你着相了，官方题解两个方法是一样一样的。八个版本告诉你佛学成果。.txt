对于这道题目一开始以为是统计深度，于是利利索索用栈写完了。边写边想这什么题啊怎么啰里啰唆一大堆什么拆分跟返回值也没关系啊。错误版本0
```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        stack, res = [], []
        for c in seq:
            if c == "(":
                stack.append("(")
                res.append(len(stack)-1)
            else:
                stack.pop()
                res.append(len(stack))

        return res
```
还别说，非常符合测试用例“(()())”，输出符合预期，[0,1,1,1,1,0]。
一提交我就满脑子问号，这究竟是什么情况。

经过仔细地阅读和审慎地思考，按照字面意思写出了新的版本1。
```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        a, b, stack, res = [], [], [], []
        for s in seq:
            if s == "(":
                stack.append(s)
                if len(stack)%2==1:
                    a.append(s)
                    res.append(0)
                else:
                    b.append(s)
                    res.append(1)
            else:
                if len(stack)%2==1:
                    a.append(s)
                    res.append(0)
                else:
                    b.append(s)
                    res.append(1)
                stack.pop()
        return res
```
然后很自然地就把ab两个完全没用地数组给优化掉了，代码升级到1.1。
```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        stack, res = [], []
        for s in seq:
            if s == "(":
                stack.append(s)
                if len(stack)%2==1:
                    res.append(0)
                else:
                    res.append(1)
            else:
                if len(stack)%2==1:
                    res.append(0)
                else:
                    res.append(1)
                stack.pop()
        return res
```
然后也很自然的把只用了长度的stack给优化掉了1.2。
```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        stack, res = 0, []
        for s in seq:
            if s == "(":
                stack += 1
                if stack % 2 == 1:
                    res.append(0)
                else:
                    res.append(1)
            else:
                if stack % 2 == 1:
                    res.append(0)
                else:
                    res.append(1)
                stack -= 1
        return res
```
stack%2的余数不就是0跟1么，1的时候可以给a也可以给b啊，a可以是b，b也可以是a，aabbbbaa，阿弥陀佛，我着相了，于是1.3出炉。
```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        stack, res = 0, []
        for s in seq:
            if s == "(":
                stack += 1
                res.append(stack % 2)
            else:
                res.append(stack % 2)
                stack -= 1
        return res
```
欸，这改改参数名不就跟官方题解的第一个解法一样了么。
然后在好好观察了这段代码之后，这个stack跟res的顺序怎么看怎么难受，改！1.4
```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        stack, res = 0, []
        for s in seq:
            if s == "(":
                stack += 1
                res.append(stack % 2)
            else:
                stack -= 1
                res.append(1-stack % 2)
        return res
```
等等，我好像隐约感受到还有能优化的地方，对啊，stack这个参数不管+1还是-1，只用到它的奇偶啊，加1跟减1都是一样的，你看这个数增也是减，减也是增，是不是很神奇。1.5
```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        stack, res = 0, []
        for s in seq:
            stack += 1
            if s == "(":
                res.append(stack % 2)
            else:
                res.append(1-stack % 2)
        return res
```
欸这个stack，怎么跟当然位置一样了啊，优化之。1.6
```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        res = []
        for i, s in enumerate(seq):
            if s == "(":
                res.append(i % 2)
            else:
                res.append(1-i % 2)
        return res
```
这怎么跟官方题解2又一样了？？？
看山是山，看水是水；看山不是山，看水不是水；看山又是山，看水又是水。
对于这道题，我只想说，爱谁谁，想看谁看谁，我改得脑子疼。
