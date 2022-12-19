### 解题思路
- 利用栈的思想：
 如果是数字，则压入栈；若为符号，即执行“pop取栈顶 -> pop取新栈顶 -> 计算”操作。
 具体代码为：

### 代码

```python3
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        
        symbol = ["+","-","*","/"]
        recList = []

        if len(tokens) == 0: return 0
        else:
            for c in tokens:
                if c not in symbol:
                    recList.append(c)
                else:
                    b = int(recList.pop())
                    a = int(recList.pop())
                    if c == "+":
                        recList.append(str(a+b))
                    elif c == "-":
                        recList.append(str(a-b))
                    elif c == "*":
                        recList.append(str(a*b))
                    elif c == "/":
                        recList.append(str(int(a/b)))
            return recList[0]
```

### 注意事项
#### 1、Python2和Python3的除法差异：
- Python2：a/b为整除，且向下取整
- Python3：a/b可保留小数，使用int()函数只保留整数部分

#### 2、执行效率
- 执行用时:76 ms, 在所有 python3 提交中击败了92.18%的用户
- 内存消耗:13 MB, 在所有 python3 提交中击败了100.00%的用户

#### 3、思路类似LeetCode题：
- 20. 有效的括号