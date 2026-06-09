### 解题思路
可以先把字符串逆序，然后统计右括号的数量count，每遇到一个左括号，右括号的数量减一，当遇到左括号而右括号的数量为0时，则删掉这个左括号，遍历一遍后如果count为0，直接返回答案，否则在正序遍历一遍，遇到左括号就删除，并且count减一，直到count等于0

### 代码

```python3
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        string = list(s)[::-1]
        count = 0
        for i in range(len(string)):
            if string[i] == '(' and count == 0:
                string[i] = ''
            elif string[i] == ')':
                count += 1
            elif string[i] == '(' and count != 0:
                count -= 1
        if count != 0:
            for i in range(len(string)-1,-1,-1):
                if count == 0:
                    break
                if string[i] == ')':
                    string[i] = ''
                    count -= 1
        return ''.join(string[::-1])
```