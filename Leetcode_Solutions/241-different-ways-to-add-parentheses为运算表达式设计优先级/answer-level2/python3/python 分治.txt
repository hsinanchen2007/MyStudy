

- 每遇到一个运算符，就分开左右两边，重新带入函数运算
- 函数遍历字符串，把本次所有的运算结果保存到temp, 返回

```ruby
class Solution:
    def diffWaysToCompute(self, input):
        if input.isdigit():
            return [int(input)]
        elif not input:
            return []
        tem = []
        for k in range(len(input)):
            if input[k] == '+':
                tem.extend([i + j for i in self.diffWaysToCompute(input[:k]) for j in self.diffWaysToCompute(input[k + 1:])])
            elif input[k] == '-':
                tem.extend([i - j for i in self.diffWaysToCompute(input[:k]) for j in self.diffWaysToCompute(input[k + 1:])])
            elif input[k] == '*':
                tem.extend([i * j for i in self.diffWaysToCompute(input[:k]) for j in self.diffWaysToCompute(input[k + 1:])])
        return tem
```
