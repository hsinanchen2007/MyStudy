### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def minNumber(self, nums: List[int]) -> str:
        b = sorted([str(i) for i in nums])
        re = ""
        ori = []
        while ori !=b:#防止重复数字没有替换位置
            ori = b.copy()
            for i in range(len(b)-1):
                if b[i] == b[i+1][0:len(b[i])] and b[i] != b[i+1]:
                    if b[i+1]+b[i]<b[i]+b[i+1]:
                        x = b[i]
                        b[i] = b[i+1]
                        b[i+1] = x
        for i in b:
            re = re+i
        return (re)
```