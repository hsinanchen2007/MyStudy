### 解题思路
一次遍历，一个变量储存当前分组的起始位置，开始新的分组前判断前一分组的长度大小，满足标准则加入结果集中。

### 代码

```python3
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        if len(S)<3:
            return []
        lasts=0
        lens=1
        res=[]
        for i in range(1,len(S)):
            if S[i]==S[lasts]:
                lens+=1
            else:
                if lens>=3:
                    res.append([lasts,i-1])
                lasts=i
                lens=1
        if lens>=3:
            res.append([lasts,i])
        return res
```

![image.png](https://pic.leetcode-cn.com/0cd4b97fdd358d7a9c685b1fa0e4474228885be615c44f573982ed0ce1d731df-image.png)
