# 思路
`A`是字符和索引都正确的，`B`是字符正确但位置不正确的。直观来看，`guess`中猜对的字符数即是`A+B`，获取`a`是容易的，只需遍历一次。
但是，哪些是猜对的（记为`tmp`）呢？示例所给两个例子很具有代表性：
- 例1：`secret = "1807", guess = "7810"`对于不重复字符串，只需取交集即可，`tmp=set(secret)&set(guess)`
- 例2：`secret = "1123", guess = "0111"`对于有重复字符串，取交集会自动去重，此情况下`tmp=set(secret)&set(guess)={1}`，我们期望的是`tmp={1,1}`(表示不准确，集合自动去重，应为`tmp=[1,1]或tmp=(1,1)`，但列表/元组不支持集合运算)。

针对例2的情况，我们怎么解决呢？我能想到的只有下面这种了。先集合取交集，然后统计重复的数目，在`secret`和`guess`中取`minimum`：
```
secret.count("1")=2
guess.count("1")=3
minimun=min(2,3)=2
```
例2中重复字符只有`"1"`，实际上可能不止，例如`secret = "112322", guess = "201121"`中`"1"`和`"2"`都是重复字符，所以我们要加起来。

因此有了下面的代码.............
# 代码
```
class Solution:
    def getHint(self, secret: str, guess: str) -> str:        
        a=0
        for i,j in zip(secret,guess):
            if i==j:
                a=a+1
        tmp=list(set(secret)&set(guess))
        count=0
        for i in range(len(tmp)):
            count=count+min(secret.count(tmp[i]),guess.count(tmp[i]))
        return str(a)+'A'+str(count-a)+'B'
```
# 结果
运行结果48ms
![QQ截图20191112110527.png](https://pic.leetcode-cn.com/96a49c37c8a756b46f5010e1ca5d331e2f67acca68d8236d0ecae0b3c1321354-QQ%E6%88%AA%E5%9B%BE20191112110527.png)
