### 解题思路

- 本想使用FSM，后来发现也没有这个必要。
- 运算符存在一个栈内，每个元素包含运算符及优先级，
- 数字放在另一个栈内，方便起见，转为整形。
- 每当看到"("，就将当前优先级+1，遇见")"就将优先级-1。
- 将基础运算提炼为一个函数便于多次调用
- 注意扫描到最后时，需要考虑数字是否都入栈了
- 扫描完全部字符，需要挨个将运算符栈里的运算符弹出计算
- 最后结果存在数字栈内，应该只剩一个了
- 因为题目说明不会有无效情况，所以无需考虑异常case

### 代码

```python3
class Solution:
    def calculate(self, s: str) -> int:
        number = ''         # - current number
        level = 0           # - current op level
        number_stack = []   # - int number stack
        op_stack = []       # - element as (op,level)

        # - pop 2 numbers and 1 op, and do once calculate
        def calc_op():
            op, _ = op_stack.pop()
            right = number_stack.pop()
            left = number_stack.pop()
            
            if op == '+':
                number_stack.append(left + right)
            elif op == '-':
                number_stack.append(left - right)
            else:
                pass
                
        # - scan chars in s
        for c in s:
            if '0' <= c <= '9':
                # - update number
                number += c
            else:
                # - push number in number_stack
                if number:
                    number_stack.append(int(number))
                    number = ''

                if c in ['+', '-']:
                    # - check operator level with op_stack[-1],
                    # - if current level is not greater than op in stack,
                    # - calculate the op in stack
                    while op_stack and (op_stack[-1][1] >= level):
                        calc_op()

                    # - push current op in op_stack
                    op_stack.append((c, level))
                elif c == '(':
                    level += 1
                elif c == ')':
                    level -= 1
                else:
                    pass
        
        # - if end with number
        if number:
            number_stack.append(int(number))

        # - check if still has op to calc
        while op_stack:
            calc_op()

        return number_stack[0]

```