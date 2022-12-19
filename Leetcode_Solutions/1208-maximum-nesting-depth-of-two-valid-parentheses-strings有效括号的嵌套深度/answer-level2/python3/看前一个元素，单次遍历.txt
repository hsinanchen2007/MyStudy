# 概述
看到这道题的时候以为是个二叉树遍历问题，没想到是个数组问题。这道题主要的解决思路是观察题目的示例，然后找到其中核心要解决的问题是什么。搞清楚内在的核心问题，方案就渐渐浮现出来了。

# 思路
这道题需要做的是把这个输入的有效括号字符串拆分成两部分，拆分需要满足两个条件：
（1）两个部分都满足有效括号字符串
（2）两个字符串的最大嵌套深度最小

第一个条件需要满足每个新串的左右括号数量相等，这个相对于比较容易实现。所以重点是第二个条件，如何使两个字符串的最大嵌套深度最低呢？
我通过观察发现，如果当前括号和他前一个括号相同的话，会导致更深的深度，因此需要把这种给分开，如果不相同的话其实是不会增加最大深度的。因此基于一个比较简单的逻辑就能够把这两部给区分开。

# 代码

```python
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:

        answer = [0]
        for i, s in enumerate(seq):
            if i == 0:
                answer.append(0)
            else:
                pre_s = seq[i-1]

                if pre_s == s:
                    if answer[-1] == 1:
                        answer.append(0)
                    else:
                        answer.append(1)
                else:
                    if answer[-1] == 1:
                        answer.append(1)
                    else:
                        answer.append(0)
        #print (answer)
        return answer[1:]
```