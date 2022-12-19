### 解题思路
此处撰写解题思路
参考了其他人的代码,主要用字典和最里面的符号必定对称解决,但是由于要考虑各自特殊情况,难度其实蛮大的.

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        a_list = []
        look_up = {'(': ')', '[': ']', '{': '}'}
        for i in s:
            if i in look_up:
                a_list.append(i)
            elif len(a_list) == 0 or look_up[a_list.pop()] != i:
                return False
        
        return len(a_list) == 0
```