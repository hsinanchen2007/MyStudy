```
from collections import defaultdict
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        # 该题与接雨水的题目有相似之处， 两字符相等，则等价于高度一样， 字符字典序越小，则高度越低
        #当两高度一样的柱子中间有更低的柱子时，则需要删除前面等高的柱子
        if not s:
            return ""
        numdict = defaultdict(int) #计算每个字符的数目，当数目大于1时，才可以删除
        curdict = defaultdict(int) #计算遍历到当前字符串时，栈中是否有该字符
        for c in s:
            numdict[c] += 1
        stack = []
        for c in s:
            if curdict[c] < 1:  # 如果当前栈中没有该字符，则需要进栈
                while stack and c <= stack[-1] and numdict[stack[-1]] > 1:
                # 如果栈中没有该字符， 且该字符字典序比栈顶字符顺序要小，且后面还会出现该栈顶字符，则
                #该字符需要出栈，此时产生的字符串字典序会更小，如栈顶字符是：b 当前字符是：a，且后续还会出现字符b，则显然...ba.... > ...a....b, 因此b字符要出栈
                    numdict[stack[-1]] -= 1
                    curdict[stack[-1]] -= 1
                    stack.pop()
        # if numdict[c] < 1: 
                stack.append(c)
                curdict[c] += 1
            else:
                numdict[c] -= 1 #如果当前栈中有该字符，虽然不需要进栈，但是字符总数的数目要减1， 
                                #用来表示从该位置开始到s结束， numdict[c] = (该字符还可能出现的次数 + 1) 

        return "".join(stack)



```
