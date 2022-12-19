### 辅助栈
![image.png](https://pic.leetcode-cn.com/05ffc80ed87fa653cf9c6e6b59f2b07f8b5f597e41499ea91e2a40bb6a6ba589-image.png)

- 使用辅助栈来进行匹配,首先明确一点具有奇数个字符的一定不能匹配成功,这就是单身狗的悲哀,没错你就是剩下的那一个 哈哈哈
- 根据栈的先入后出的特点,在结合代码讲解下:
- 还是给定一个例子`"{[]}"`
1. 初始的时候`stack`栈为空,如果入栈的第字符为`'{','[','('`,那么我们在`stack`中加入他们的男朋友即`'}',']',')'`,这里为什么不加入原始的字符而是加入它的对称字符,是因为下面在匹配的时候直接判断是否相等就可以了,就省了一步判断;如果当栈为空时,且入栈的第一个字符为`'}',']',')'`,那么后面的不能与之匹配,直接返回`false`
2. 然后一次将字符串`s`中的字符根据上面的规则入栈,如果当前的字符跟栈顶的字符相等,那么将栈顶元素出栈,继续执行
3. 最后如果栈为空,说明匹配完成,否则没有完成匹配
### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) & 1:
            return False
        stack = []
        for i in s:
            if i == '(':#加入字符的反面
                stack.append(')')
            elif i == '[':
                stack.append(']')
            elif i == '{':
                stack.append('}')
            elif not stack or i != stack.pop():
                return False
        if not stack:
            return True
        return False
                

        
```