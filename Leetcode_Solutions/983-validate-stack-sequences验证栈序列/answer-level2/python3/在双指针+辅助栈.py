### 解题思路
定义一个辅助栈和两个指针,遍历popped数组,思路都在注释里
![image.png](https://pic.leetcode-cn.com/ff20d3d692ad75643f0bce9ff613add901731b2af165ad7af75dc8c626489bb3-image.png)

### 代码

```
class Solution:
    def validateStackSequences(self, pushed: [int], popped: [int]) -> bool:
        stack=[] #辅助栈
        i=0 #pushed中移动的指针
        j=0 #popped中移动的指针
        n=len(pushed)
        while j <n: #popped全部遍历完才算结束
            if not stack: #如果辅助栈为空就添加
                stack.append(pushed[i])
                i+=1
            while i<n and stack[-1]!=popped[j]: #如果辅助栈的栈顶元素不等于要弹出元素,就向其中添加
                stack.append(pushed[i])
                i+=1
            top=stack.pop() #弹出辅助栈栈顶元素
            if top==popped[j]: #如果辅助栈栈顶元素与弹出元素相同,就继续,否则返回False
                j+=1
            else:
                return False
        return True
```