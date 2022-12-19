### 解题思路
- 只需要记录有多少个A和多少个L
- 用python可以使用函数，s.count('A'),如果大于1，则就return
- 那如何处理连续的L？判断里面是否有LLL，可以直接用‘LLL' in s的操作，如果没有，说明没有超过两个连续的L


### 代码

```python3
class Solution:
    def checkRecord(self, s: str) -> bool:
        return not (s.count('A')>1 or 'LLL'in s)
```