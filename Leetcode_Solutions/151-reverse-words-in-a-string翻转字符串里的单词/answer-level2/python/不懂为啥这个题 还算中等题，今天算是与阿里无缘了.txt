### 解题思路
字符串的基本操作的，可惜 可惜 可惜
### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        list_str=s.split()
        str_list=[]
        for i in list_str[::-1]:
            str_list.append(i)
        return ' '.join(str_list)
```