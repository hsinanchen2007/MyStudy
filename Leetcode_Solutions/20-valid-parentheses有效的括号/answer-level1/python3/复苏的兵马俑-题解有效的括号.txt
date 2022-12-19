### 题解思路1（正则法-re.findall()）
LeetCode中提交执行结果-执行用时：200 ms，内存消耗：13.5 MB。

### 代码
```python
import re
class Solution:
    def isValid(self, s: str) -> bool:
        no_space_s = s.replace(' ','')
        while no_space_s:
            re_list = re.findall('\(\)|\[]|{}',no_space_s)
            if not re_list:
                return False
            for char in re_list:
                no_space_s = no_space_s.replace(char,'')
        return True
```

### 测试代码
```python
print('字符串“()”是否有效：',Solution().isValid("()"))
print('字符串“”是否有效：',Solution().isValid(""))
print('字符串“[”是否有效：',Solution().isValid("["))
print('字符串“]”是否有效：',Solution().isValid("]"))
print('字符串“{[]}”是否有效：',Solution().isValid("{[]}"))
print('字符串“()[]{}”是否有效：',Solution().isValid("()[]{}"))
print('字符串“(]”是否有效：',Solution().isValid("(]"))
print('字符串“([)]”是否有效：',Solution().isValid("([)]"))
```

### 运行结果
```python
字符串“()”是否有效： True
字符串“”是否有效： True
字符串“[”是否有效： False
字符串“]”是否有效： False
字符串“{[]}”是否有效： True
字符串“()[]{}”是否有效： True
字符串“(]”是否有效： False
字符串“([)]”是否有效： False
```

### 题解思路2（正则法-re.search()）
LeetCode中提交执行结果-执行用时：312 ms，内存消耗：13.5 MB。

### 代码
```python
import re
class Solution:
    def isValid(self, s: str) -> bool:
        no_space_s = s.replace(' ','')
        while no_space_s:
            if re.search('\(\)|\[]|{}',no_space_s):
                re_string = re.search('\(\)|\[]|{}',no_space_s).group()
                no_space_s = no_space_s.replace(re_string, '')
            else:
                return False
        return True
```

### 测试代码
```python
print('字符串“()”是否有效：',Solution().isValid("()"))
print('字符串“”是否有效：',Solution().isValid(""))
print('字符串“[”是否有效：',Solution().isValid("["))
print('字符串“]”是否有效：',Solution().isValid("]"))
print('字符串“{[]}”是否有效：',Solution().isValid("{[]}"))
print('字符串“()[]{}”是否有效：',Solution().isValid("()[]{}"))
print('字符串“(]”是否有效：',Solution().isValid("(]"))
print('字符串“([)]”是否有效：',Solution().isValid("([)]"))
```
运行结果：
```python
字符串“()”是否有效： True
字符串“”是否有效： True
字符串“[”是否有效： False
字符串“]”是否有效： False
字符串“{[]}”是否有效： True
字符串“()[]{}”是否有效： True
字符串“(]”是否有效： False
字符串“([)]”是否有效： False
```

### 题解思路3（堆栈法）
LeetCode中提交执行结果-执行用时：32 ms，内存消耗：13.5 MB。

### 代码
```python
class Solution:
    def isValid(self, s: str) -> bool:
        dic = {'{': '}',  '[': ']', '(': ')', '#': '#'}
        stack = ['#']
        for c in s:
            if c in dic:
                stack.append(c)
            elif dic[stack.pop()] != c: return False
        return len(stack) == 0
```

### 测试代码
```python
print('字符串“()”是否有效：',Solution().isValid("()"))
print('字符串“”是否有效：',Solution().isValid(""))
print('字符串“[”是否有效：',Solution().isValid("["))
print('字符串“]”是否有效：',Solution().isValid("]"))
print('字符串“{[]}”是否有效：',Solution().isValid("{[]}"))
print('字符串“()[]{}”是否有效：',Solution().isValid("()[]{}"))
print('字符串“(]”是否有效：',Solution().isValid("(]"))
print('字符串“([)]”是否有效：',Solution().isValid("([)]"))
```
### 运行结果
```python
字符串“()”是否有效： True
字符串“”是否有效： True
字符串“[”是否有效： False
字符串“]”是否有效： False
字符串“{[]}”是否有效： True
字符串“()[]{}”是否有效： True
字符串“(]”是否有效： False
字符串“([)]”是否有效： False
```

### 题解思路4（堆栈法）
LeetCode中提交执行结果-执行用时：56 ms，内存消耗：13.3 MB。

### 代码
```python
class Solution:
    def isValid(self, s: str) -> bool:
        dic = {'}': '{',  ']': '[', ')': '('}
        stack = []
        for char in s:
            if char in dic:
                top_element = stack.pop() if stack else '#'
                if dic[char] != top_element:
                    return False
            else:
                stack.append(char)
        return not stack
```

### 测试代码
```python
print('字符串“()”是否有效：',Solution().isValid("()"))
print('字符串“”是否有效：',Solution().isValid(""))
print('字符串“[”是否有效：',Solution().isValid("["))
print('字符串“]”是否有效：',Solution().isValid("]"))
print('字符串“{[]}”是否有效：',Solution().isValid("{[]}"))
print('字符串“()[]{}”是否有效：',Solution().isValid("()[]{}"))
print('字符串“(]”是否有效：',Solution().isValid("(]"))
print('字符串“([)]”是否有效：',Solution().isValid("([)]"))
```

### 运行结果
```python
字符串“()”是否有效： True
字符串“”是否有效： True
字符串“[”是否有效： False
字符串“]”是否有效： False
字符串“{[]}”是否有效： True
字符串“()[]{}”是否有效： True
字符串“(]”是否有效： False
字符串“([)]”是否有效： False
```