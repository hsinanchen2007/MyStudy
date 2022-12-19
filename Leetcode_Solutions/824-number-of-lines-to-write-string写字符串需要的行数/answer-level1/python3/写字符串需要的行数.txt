### 解题思路
超过88%

### 代码

```python3
class Solution:
    def numberOfLines(self, widths: List[int], S: str) -> List[int]:
        vol, temp, count = ord('a'), 0, 1
        for i in S:
            temp += widths[ord(i) - vol]
            if temp > 100:
                temp, count = widths[ord(i) - vol], count + 1
        return [count, temp]
            
        

```