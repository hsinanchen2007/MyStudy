### 解题思路

考虑每个位置的雨水量

从左到右扫描，记录左侧的每个位置的最大值，

然后从右到做扫描，记录每个位置右侧的最大值，

两者之差就是当前位置的雨水量

时间复杂度`O(n)`, 空间复杂度可以优化为`O(n)`，两次扫描只需要使用一个数组即可

### 代码

```python3
class Solution:
    def trap(self, height: List[int]) -> int:
        l = []
        r = []
        tmp = 0
        for x in height:
            tmp = max(tmp, x)
            l.append(tmp)
        tmp = 0
        for x in height[::-1]:
            tmp = max(tmp, x)
            r.append(tmp)
        r = r[::-1]
        res = 0
        for i in range(len(l)):
            res += min(l[i], r[i]) - height[i]
        return res
```