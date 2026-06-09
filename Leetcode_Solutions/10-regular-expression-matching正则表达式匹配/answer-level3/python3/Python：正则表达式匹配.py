### 解题思路
抖个机灵，反正是判断嘛，那就以这个正则开头，结尾，必然是符合的，几乎没有算法价值……
# 莫学

### 代码

```python3
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        return True if re.match(p+'$',s) else False
```

### 解题思路
一般的字符串问题，动态规划或者回溯都是可以完成的，这才是正经算法