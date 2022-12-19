### 解题思路
此处撰写解题思路

### 代码

```python3

class Solution:
    def frequencySort(self, s: str) -> str:
        s_list = sorted(set(s),key=lambda x:s.count(x),reverse=True)
        return ''.join([i*s.count(i) for i in s_list])
        
            
        
        
```