### 解题思路
字符串切分成列表，如果满足first和second同时出现，记录下third。

### 代码

```python3
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        text_list = text.split(' ')

        res = []

        for i in range(0, len(text_list)-2):
            if text_list[i] == first and text_list[i+1] == second:
                res.append(text_list[i+2])
        
        return res
```