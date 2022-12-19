### 解题思路
![image.png](https://pic.leetcode-cn.com/66b5000be35c445905fe1dfc442b1368c6faf0a26e3007edb307223d2c18d46b-image.png)
- 我们这道题目其实是考察栈的本质,我们在此需要使用一个辅助栈来保存元素
- 我们可以找到判断一个序列是不是栈的弹出序列的规律:
1. 如果下一个弹出的数字刚好是栈顶元素,那么直接弹出
2. 如果下一个弹出的元素不在栈顶,则把压栈序列的数字压入辅助栈,知道把下个需要弹出的数字压入栈顶为止
3. 如果所有的数字都压入了辅助栈仍没有找到下一个弹出元素,那么该序列不可能能使一个弹出序列
- 时间复杂度`O(2n)`,空间复杂度`O(n)`
### 代码

```python
class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        if not pushed and not popped:
            return True
        stack = []#设置辅助栈
        while popped:
            temp = popped.pop(0)
            if not stack:# 辅助栈为空时,添加元素
                stack.append(pushed.pop(0))
            if stack[-1] == temp:# 当辅助栈的栈顶元素刚好等于当前要弹出的元素,直接弹出
                stack.pop()
            else:# 不等于时,把压栈序列的数字压入辅助栈,知道把下个需要弹出的数字压入栈顶为止
                while temp != stack[-1] and pushed:
                    stack.append(pushed.pop(0))
                if temp == stack[-1]:
                    stack.pop()
                else:#此时说明压栈序列为空了也没找到那个要弹出的元素,说明不符合
                    return False
        return True

            
```