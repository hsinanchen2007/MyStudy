### 解题思路
学习结果里面的时间最佳方法。

**本题关键思路**：匹配对以左括号为key，右括号为对应的value放入字典（也就是哈希表），通过查找字典来确定括号是否匹配。

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        # 左括号作为key，右括号作为value。
        # stack里面先放了一个？，因此需要一个key为？的放入字典与之对应。
        # 这样如果第一个字符为右括号时，栈pop出来能有值而不为空，不然没东西pop就报错了。
        match_dict = {'(': ')', '{': '}', '[': ']', '?': '?'}
        stack = ['?']
        for i in s:
            # 还是老套路，如果来的字符是左括号，就入栈，只不过左括号的集合用字典key表示了
            if i in match_dict:
                stack.append(i)
            # 检查pop出来的左括号在字典对应的值是否等同于需要检查的右括号
            elif match_dict[stack.pop()] != i:
                return False
        return len(stack) == 1
```