### 解题思路
有用的信息可以消除或者减小不确定性，我觉得很有道理，简单的暴力没有把题目信息完全用完，这必然存在优化。
从左到右，从上到下都是递增的，这个信息怎么用？
首先看难点在哪里
如果我从头开始搜索，我们从上到下，从左到右都是增的，如果target小于maxtix[0][0]还好说，直接返回False
如果target大于maxtix[0][0]呢？我们有两条路走，走下或者走右，因为都是递增的嘛，所以我们只能逐一检查，这就是暴力搜索了。
那我们就想，有没有一个地方大的选择一条路，小的选择一条路，这样是不是就好很多。
从左下角向上，或者从右上角向下，就是这样的地方呀，于是乎找到晴天。

### 代码

```python3
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        i,j=len(matrix)-1,0
        while i>=0 and j<=len(matrix[0])-1:
            if matrix[i][j]>target:
                i-=1
            elif matrix[i][j]<target:
                j+=1
            else:
                return True
        return False
        
```