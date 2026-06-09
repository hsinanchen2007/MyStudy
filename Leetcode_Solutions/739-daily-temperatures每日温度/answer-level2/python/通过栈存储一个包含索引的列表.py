### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def dailyTemperatures(self, T):
        """
        :type T: List[int]
        :rtype: List[int]
        """
        #入栈什么？索引或者是包含索引的一个列表
        # 什么时候出栈？当栈顶元素小于当前元素时
        # 什么时候入栈？当栈顶元素大于当前元素时
        stack = []
        result = [0 for i in range(len(T))]
        for i in range(len(T)):
            #以下这个循环很重要，不一定要一一判断
            while stack and T[i] > T[stack[-1][0]]:
                temp = stack.pop()
                temp[1] = i - temp[0]
                result[temp[0]] = temp[1]
            #既然stack为空以及T[i] < T[stack[-1][0]]都是要直接入栈，那么放在一起岂不美哉
            else:
                stack.append([i,0])
                
        return result
```