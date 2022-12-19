### 解题思路
使用数组res记录N个人每个人被他人信任的净次数，初始为1，被他人信任则加1，信任他人则减1，最终只有法官的数与N相等，最终遍历数组res, N对应的数组下标即为小镇法官。
### 代码

```python3
class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        res=[1]*(N+1)
        res[0]=-1
        for pair in trust:
            res[pair[1]]+=1
            res[pair[0]]-=1
        for ii,n in enumerate(res):
            if n==N:
                return ii
        return -1
```

![image.png](https://pic.leetcode-cn.com/2b3623a53c5ca1ffa29d7229b24fc3c4acd57c4185851c175b44b00516571266-image.png)
