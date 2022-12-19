求解方程就是要把方程简化，求出 `x` 的个数 `x_count` 和剩余数值 `num`：

```
x_count * x = num
```

最终需要求的结果就是 `num / x_count`。

我们可以把方程式根据等号分为左右两个式子，对左右两个式子进行遍历，分别求出 `x` 的数量和剩余数值。

在遍历过程中：

1. 遇到字符为 `+` 或 `-`（即遇到运算符）：对该运算符之前的公式进行结算
2. 遇到字符不是运算符：
   1. 遇到字符为 `x`：根据 `x` 前面跟着的数字和运算符，对 `x` 的个数进行结算
   2. 遇到字符为数字：把该数字记录下来（我在这里用了 Python 的列表进行记录），当遇到下一个运算符或符号 `x` 时进行结算

⚠️注: 会遇到 `0x` 这样的写法。

```python
class Solution:
    def solveEquation(self, equation: str) -> str:
        formula = equation.split("=")
        
        def get_count(formula):
            num_list = []
            pre_symbol = "+"
            x_count = 0
            num = 0
            for c in formula:
                # 不是运算符
                if c != "+" and c != "-":
                    if c == "x":
                        add_x = 1 if len(num_list) == 0 else int("".join(num_list))
                        if pre_symbol == "+":
                            x_count += add_x
                        else:
                            x_count -= add_x
                        num_list = [] # 清空列表
                    else:
                        # 是数字
                        num_list.append(c)
                # 是运算符
                else:
                    if len(num_list) != 0:
                        num = eval(str(num) + pre_symbol + "".join(num_list))
                    pre_symbol = c
                    num_list = []
            # 最后遗漏的数字
            if len(num_list) != 0:
                num = eval(str(num) + pre_symbol + "".join(num_list))
            return [x_count, num]
        
        left = get_count(formula[0])
        right = get_count(formula[1])

        x_count = left[0] - right[0]
        num = left[1] - right[1]
                
        # 计算结果
        if x_count == 0 and num == 0:
            return "Infinite solutions"
        if x_count == 0 and num != 0:
            return "No solution"
        return "x=" + str(-num // x_count)
```
