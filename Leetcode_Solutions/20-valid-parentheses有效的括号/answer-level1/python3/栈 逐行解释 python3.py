# 题解
有效的括号问题，一般使用栈来解决，若出现一个右括号，判断栈顶的是否为相匹配的左括号，是则出栈，否则入栈。遇到左括号就入栈。显然，有效的括号一定保证最终栈为空，若出现一个右括号，栈已空，则一定无效。
## 栈

 1. 初始化括号对应关系$dict=\{ ")":"(","\}":"\{","]":"["\}$，$stack=[]$
 2. 遍历括号字符串，$i$，遍历区间$[0,len(s))$：
 	+ 若$s[i]$为右括号：
 		+ 若栈不为空：若栈顶括号和$s[i]$匹配，则将栈顶退栈。否则：将当前右括号进栈。
 		+  若栈为空，返回$False$
 	+ 若为左括号：将其入栈
 
 3. 返回栈是否为空

 

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
### 复杂度分析
 - 时间复杂度：$O(n)$
 - 空间复杂度：$O(n)$

### Python
```python
class Solution:
    def isValid(self, s: str) -> bool:
        dict={")":"(","}":"{","]":"["}
        stack=[]
        for i in range(len(s)):
            if(s[i] in dict):
                if(stack):
                    if(stack[-1]==dict[s[i]]):
                        stack.pop()
                    else:
                        stack.append(s[i])
                else:
                    return False
            else:
                stack.append(s[i])
        return not stack
```
