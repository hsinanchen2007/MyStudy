### 解题思路
依然使用Python的列表初始化一个栈，列表末尾作为栈顶。
可以把此题看作一个消除游戏，消除标记为"#"
依次遍历字符串
当字符为"#"时,此时查看栈是否为空，若不为空，则栈顶元素出栈，为空的话什么也不做，继续遍历。
当字符串不是"#"时，直接入栈。
最后遍历完成之后，将栈中元素拼接起来返回。
最后直接判断两个经过消除的字符串是否一致即可。

值得一提的是：
1.在判断字符是否为"#"时，使用in判断要比使用==判断快16ms，直接超过了绝大部分人
2.使用while循环似乎比用for循环更加省时

### 代码

```python3
class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        reduced_S = self.reduced(S)
        reduced_T = self.reduced(T)

        if reduced_S == reduced_T:
            return True
        else:
            return False

    def reduced(self, string_to_reduced):
        Stack = []
        index = 0
        while index < len(string_to_reduced):
            symbol = string_to_reduced[index]
            if symbol in "#":
                if Stack != []:
                    Stack.pop()
            else:
                Stack.append(symbol)
            
            index += 1

        return "".join(Stack)
```