
### 我实在想不到为什么要用栈。。


拿到这道题，第一反应是计数，且要在碰到后括号`)`的时候，去判断已经遍历过的`(`和`)`的个数（此时的`)`的个数要加上当前碰到的这个`)`）是不是相等，如果相等，则说明我们遇到了外层括号，那么这个括号需要删掉，用栈反而耗费空间，不如用字符串累加和暂存：
![image.png](https://pic.leetcode-cn.com/02d55cf4748a5c0fff92b1addc499f31edd76a545c8e5a2a9a3bd82a09c6265b-image.png)


```python
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        res = ''
        
        tmp = ''
        left = 0
        right = 0
        
        for i in S:
            if i == '(':
                tmp += i
                left += 1
            else:
                if right+1 == left:
                    tmp = tmp[1:]
                    res += tmp
                    tmp = ''
                    left = 0
                    right = 0
                else:
                    tmp += i
                    right += 1
                    
        return res
```


### 2.简化空间
这个代码当时我写出来我都看着崩溃，太长太冗余太渣渣。。。
那么能不能简化一点，这里我用了两个变量在保存前括号和后括号的个数：`left`和`right`，两个值都是累加，需要最后判断是不是相等，那么我能不能用一个变量来保存，遇到`left`就`+1`，遇到`right`就`-1`：

```python
class Solution:
    def removeOuterParentheses(self, S: str) -> str:
        res = ''
        
        tmp = ''
        ended = 0
        
        for i in S:
            if i == '(':
                ended += 1
            else:
                ended -= 1
            if ended == 0:  # 把ended的判断拿出来，和前一个ifelse平级，能够将tmp+=i整合到一起
                res += tmp[1:]
                tmp = ''
            else:
                tmp += i  

        return res
```


### 3.如何自律如何恢复状态
每天都立下100个flag，每天要打101次脸。。。
每天都低迷，都情绪不佳，每天都在逃避在畏难。。
可能是想要的太多，那么为什么不能“少就是多”。。
如果写东西变成痛苦的事情，那么就减少一些，少些一些，但是不能因此而不做题啊。
如果做题太难，那为什么不敢于去看答案，并且去理解，反反复复理解呢。
要继续努力啊，你就算在北京，但是仍然有心之所向啊。

Start Over.