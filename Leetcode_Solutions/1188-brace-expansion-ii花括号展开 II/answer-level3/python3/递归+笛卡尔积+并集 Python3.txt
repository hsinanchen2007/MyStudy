**思路：**

将花括号按层展开，用变量`level`表示当前是第几层括号，初始值为`0`，遇到一个左括号`{`时，`level`值增加`1`，遇到右括号`}`时，`level`值减少`1`。用递归处理每一层，每一层的结构为`{}{}...{} + {}{}...{} + ...`，和四则运算法则同理，先调用下一层函数计算括号内的，然后先乘后加。当前层递归函数只用笛卡尔积和并集处理层数为`0`的表达式，进入下一层，就用`start`变量标记该层的起始位置，直到找到该层的结束位置时，调用下一层递归函数。遍历时候，每遇到一个逗号（`,`）就在`groups`里面新开一个`list`，遍历完后，将`groups`里的每个`list`进行笛卡尔积运算，再取并集。

**代码：**

```python
class Solution:
    def braceExpansionII(self, expression: str) -> List[str]:
        groups = [[]]
        level = 0
        for i, c in enumerate(expression):
            if c == '{':
                if level == 0:
                    start = i+1
                level += 1
            elif c == '}':
                level -= 1
                if level == 0:
                    groups[-1].append(self.braceExpansionII(expression[start:i]))
            elif c == ',' and level == 0:
                groups.append([])
            elif level == 0:
                groups[-1].append([c])
                print(c, groups)
        word_set = set()
        # 加运算，取并集
        for group in groups:
            word_set |= set(map(''.join, itertools.product(*group))) # 乘运算，取笛卡尔积
        return sorted(word_set)
```