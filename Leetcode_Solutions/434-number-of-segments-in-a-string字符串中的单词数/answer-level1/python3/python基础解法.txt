### 解题思路
1. 调用python内置的split函数
2. 遍历去判断i-1为空，i不为空，统计

### 代码

```python3
class Solution:
    def countSegments(self, s: str) -> int:
        # return len(s.split())

        seg_count = 0
        for i in range(len(s)):
            if (i == 0 or s[i-1] == ' ') and s[i] != ' ':
                seg_count += 1
        return seg_count 
```