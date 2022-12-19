### 解题思路
执行用时 :44 ms, 在所有 Python3 提交中击败了59.41%的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了5.83%的用户

思路：
1. 栈用来存储最后的输出
2. 假设一个字符串有'a''b''c''d'四种字符，那么字典序最小的排列是'abcd'
3. 因此，当输入小于栈顶元素，我们需要进行调整，逐个判断栈中的元素，将输入向前挪到合适位置：
        如果栈顶元素之后还会出现，则可以向前挪，即删除栈顶元素
        如果栈顶元素不会再在后面出现了，则不能把输入向前挪，即不能删除栈顶元素
4. 当输入大于栈顶且未在栈中出现过时，入栈
5. 当输入在栈中出现过，忽略
### 代码

```python3
class Solution:
    def removeDuplicateLetters(self, s_org: str) -> str:
        s = ''.join(['0', s_org, '0'])
        stk = [s[0]]
        for i in range(1, len(s)):
            if s[i] in stk:
                continue
            while s[i] < stk[-1]:
                if stk[-1] in s[i+1:]:
                    stk.pop()
                else:
                    break
            stk.append(s[i])
        return ''.join(stk[1:])
```