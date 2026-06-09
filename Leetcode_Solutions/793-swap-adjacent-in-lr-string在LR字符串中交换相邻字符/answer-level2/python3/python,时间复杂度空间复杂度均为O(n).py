### 解题思路
### 代码

```python3
class Solution:
    def canTransform(self, start: str, end: str) -> bool:
        def convert(start):#字符串转化为形如[('R',1)]的数组，'R'为字符，1为下标
            s = []
            for i, v in enumerate(start):
                if v == 'R':
                    s.append(('R', i))
                if v == 'L':
                    s.append(('L', i))
            return s
        s = convert(start)
        e = convert(end)
        if len(s) != len(e): return False#长度不相等
        for i in range(len(s)):
            if s[i][0] != e[i][0]:#元素不相等
                return False
            if s[i][0] == 'R' and s[i][1] > e[i][1]:#R只能向右移动，而start的R在end的R的右侧那么返回False
                return False
            if s[i][0] == 'L' and s[i][1] < e[i][1]:#L只能向左移动，而Start的L在end的L的左侧那么返回False
                return False
        return True

        


```