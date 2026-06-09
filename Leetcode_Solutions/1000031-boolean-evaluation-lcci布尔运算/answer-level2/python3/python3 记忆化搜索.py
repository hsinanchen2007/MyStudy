### 解题思路
将需要计算结果的布尔表达式根据符号递归的分成左右两边，同时统计左右两边需要计算的结果的数量。
举例：
    s = a&b, result = 0
        a, b 均代表两个布尔表达式， 期望 a & b = 0, 则需要 (a, b) 可能的结果是 (True, False), (False, True), (False, False)

    递归的拆解表达式，统计 num(a = True, b = False) num(a = False, b = True) num(a = False, b = False) 对应的数量
    则 total = num(a = True, b = False) + num(a = False, b = True) + num(a = False, b = False)
    其中 num(a = True, b = False) = num(a = True) * num(b = False)

使用备忘录记录对应表达式和能生成对应结果的数量，加速搜索。

### 代码

```python3
class Solution:
    def countEval(self, s: str, result: int) -> int:
        """
        {
            符号: {
                需要计算出的结果: {
                    [(左子式需要计算的结果，右子式需要计算的结果)]
                }
            }
            
        }
        """
        self.ops = {
            '&': {
                True: [(True, True)],
                False: [(True, False), (False, True), (False, False)]
            },
            '|': {
                True: [(True, False), (False, True), (True, True)],
                False: [(False, False)]
            },
            '^': {
                True: [(True, False), (False, True)],
                False: [(True, True), (False, False)]
            }
        }
        return self.dfs(s, result, {})
        
    def dfs(self, expression, result, memo):
        # 查询备忘录，有结果则直接返回
        if (expression, result) in memo:
            return memo[(expression, result)]
        
        # 边界情况
        if len(expression) == 1:
            val = int(expression)
            return int(bool(val) == result)
        
        # 递归计算左右子式的结果
        total = 0
        for i in range(len(expression)):
            if expression[i] in self.ops:
                for lr, rr in self.ops[expression[i]][result]:
                    total += self.dfs(expression[:i], lr, memo)*self.dfs(expression[i+1:], rr, memo)
        memo[(expression, result)] = total
        return total
```