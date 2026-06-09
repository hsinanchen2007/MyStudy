之前的题目也做了，现在一看到字符串消括号的题，首先就想到栈。
拿到本题后，思路很简单，遍历字符串，左括号的index入栈，遇到右括号，弹出栈顶元素，一通操作（识别数字，复制X份括号内容，替换字符串生成新字符串），直到栈为空。

接下来就是实现了，首先栈为空这个判断不好处理‘3[a]2[b]’这种，将此条件换为更粗暴的 '[' in s 。
其次，识别数字要搞一下，测试案例竟然有'100[leetcode]'，最粗暴的办法嘛，写个while,向前遍历，字符非数字时停止。

下面就是代码了，感觉没啥技术含量。
```
class Solution:
    
    def decodeString(self, s: str) -> str:
        
        stack = []
        
        while  '[' in s:
        
            for i, v in enumerate(list(s)):
            
                if v==']':
                                
                    j = stack.pop()
                    
                    jj = 1 ## 识别多位数的数字
                    while s[j-jj].isdigit():
                        jj += 1
                    
                    ## 拼接字符串生成新的s
                    s = s[:j-jj+1]+int(s[j-jj+1:j])*s[j+1:i]+s[i+1:]

                    ## break之后才能重新for循环新的s
                    break
                    
                elif v=='[':

                        stack.append(i)
                    
        return s
```
哪位大神能告诉我下这个时间复杂度是不是O(N)?