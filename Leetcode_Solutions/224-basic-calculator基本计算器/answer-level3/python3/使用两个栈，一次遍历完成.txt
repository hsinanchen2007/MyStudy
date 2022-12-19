### 解题思路
使用两个栈，一个用来存数字和左括号`nums`，一个用来存操作符`ops`。
当`nums`的最后两个元素是数字并且`ops`非空，就把这三个元素弹出来求值一次，再把结果压入`nums`。
如果碰到右括号，则删除`nums`的倒数第二个元素（这个元素一定是左括号），再尝试求值一次。


### 代码

```python3
class Solution:
    def calculate(self, s: str) -> int:
        nums, ops = [], []
        pos, N = 0, len(s)

        def cal() :
            if ops and len(nums) >= 2 and nums[-1] not in ['(',')'] and nums[-2] not in ['(',')'] :
                nums[-2] = nums[-1] + nums[-2] if ops[-1] == '+' else nums[-2] - nums[-1]
                del nums[-1]
                del ops[-1]

        while pos < N :
            tp = pos
            while tp < N and s[tp] in ['0','1','2','3','4','5','6','7','8','9']:
                tp += 1
            if tp != pos :
                n = int(s[pos:tp])
                nums.append(n)
                cal()
                pos = tp
                continue

            if s[pos] in ['+','-'] : ops.append(s[pos])
            if s[pos] == '(' : nums.append('(')
            if s[pos] == ')' :
                del nums[-2]
                cal()
            pos += 1
        
        return nums[-1]

```