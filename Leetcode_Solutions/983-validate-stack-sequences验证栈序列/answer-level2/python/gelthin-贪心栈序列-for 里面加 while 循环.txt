### 解题思路
同习题 [面试题31. 栈的压入、弹出序列](https://leetcode-cn.com/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/solution/gelthin-zhan-de-xu-lie-by-gelthin/)
参考了官方题解，但修改了一下，为了省去一次 append, pop 导致代码变复杂.


### for 里面加 while 循环，这种写法在 [41. 缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)习题也碰到过。




### 代码

```python3
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        ## 这里每个值都不重复不知道有什么用？
        # 官方题解给的 贪心做法，只适用于 没有重复数字的情形，我在剑指offer 的解法也是贪心
        if pushed == [] and popped == []:
            return True
        stack = []
        j = 0 # popped 指针
        # for x in pushed: # BUG:[2,1,0]
        #     if x == popped[j]:
        #         j += 1
        #     else:
        #         stack.append(x)

        for x in pushed:
            #stack.append(x)   ## 为了省去一次 append, pop 导致代码变复杂，不合算
            if x == popped[j]:
                j += 1
                while j<len(popped) and stack and stack[-1] == popped[j]:
                    stack.pop()
                    j += 1
            else:
                stack.append(x)

        while stack and j<len(pushed) and stack[-1] == popped[j]:
            stack.pop()
            j += 1
        return stack == []
        

```