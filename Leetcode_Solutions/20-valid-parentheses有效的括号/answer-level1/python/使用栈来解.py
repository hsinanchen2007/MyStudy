### 解题思路
1.对比key 如何是左半边入栈
2.如果是右半边去栈里pop一个左半边去字典里查右半边,然后对比,如果不对直接FALSE
3.最后栈为空为止
### 代码

```python
class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        valid_dict, stack = {'(': ')', '[': ']', '{': '}'}, []
        for valid in s:
            if valid in valid_dict:  # 对比key 左半边
                stack.append(valid)  # 入栈
            else:
                if len(stack) == 0:
                    return False
                # 右半边, 依据key去栈里pop一个value: 右半边 判断能否匹配
                elif valid == valid_dict[stack.pop()]:
                    continue
                else:
                    return False
        return len(stack) == 0
```