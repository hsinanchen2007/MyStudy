### 解题思路
题意：尽可能多的平衡字符串（不能调整字符串顺序）
- 尽可能短的组成，能得到尽可能多的组
- 从头开始遍历，遇到L计数加一，遇到R计数减一，计数为0说明找到一组，total+1
- 继续，直到结束，返回total

### 代码

```python3
class Solution:
    def balancedStringSplit(self, s: str) -> int:
        count = 0
        total = 0
        for v in s:
            if v=='L': count+=1
            if v=='R':count-=1
            if count==0:
                total = total +1
        return total 
```