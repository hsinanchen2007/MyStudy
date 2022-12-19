### 解题思路
这个思路可以学习下, 为每个位置(i,j)存储三个状态:当前坐标所在矩形的合法左边界, 合法有边界以及合法高度.
因此该点的矩阵面积就为(right[j]-left[j])*height[j]
这个思想感觉有点像并查集, 为每个点存储其左右边界. 这里有多存储了一个高度的状态

### 代码

```python3
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        h, w = len(matrix), len(matrix[0])
        left, right, height = [0]*w, [w]*w, [0]*w
        res = 0
        for i in range(h):
            cur_left, cur_right = 0, w # 分别代表左边界index, 和右边界index+1
            for j in range(w):
                if matrix[i][j]=='1': height[j] += 1
                else: height[j] = 0
            for j in range(w):
                if matrix[i][j]=='1': left[j] = max(left[j], cur_left)
                else: cur_left, left[j] = j+1, 0
            for j in range(w-1, -1, -1):
                if matrix[i][j]=='1': right[j] = min(right[j], cur_right) # 这里是min! 因为是求最远右边界
                else: cur_right, right[j] = j, w # 这里是w不是0!!
            for j in range(w):
                res = max(res, (right[j]-left[j])*height[j])
        return res
```

如果按照一开始的思路, 以每个位置看作其所在最大矩形的右下角进行遍历, 那dp[i][j]可以设计为以(i,j)为右下角的矩形的最大**宽度** (不是面积!)
本质是转化为了84题那样, 我们预计算最大宽度的方法事实上将输入转化成了一系列的柱状图，每一行是width个新的柱状图。我们在针对每个柱状图计算最大矩形面积

则遍历该行i时, 以(i,j)为右下角的最大矩形面积应该为
```
for k in range(i, -1, -1):
                    width = min(width, dp[k][j])# 代表了第j列在k行的最小宽度, 也就是矩阵的最小宽度
                    maxarea = max(maxarea, width * (i-k+1)) 
```

```
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        maxarea = 0

        dp = [[0] * len(matrix[0]) for _ in range(len(matrix))] # 这里的dp[i]指宽度
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] == '0': continue

                # compute the maximum width and update dp with it
                width = dp[i][j] = dp[i][j-1] + 1 if j else 1 # 下面用栈的时候因为是高度所以为0, 这里为宽度所以为1!

                # compute the maximum area rectangle with a lower right corner at [i, j]
                for k in range(i, -1, -1):
                    width = min(width, dp[k][j])
                    maxarea = max(maxarea, width * (i-k+1))
        return maxarea
```
作者：LeetCode
链接：https://leetcode-cn.com/problems/maximal-rectangle/solution/zui-da-ju-xing-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


也可用栈, 这时候dp[i]的含义就变成i位置的高度了. i也不代表矩阵右下角的点了
```
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix: return 0
        h, w = len(matrix), len(matrix[0])
        dp, res = [0]*w, 0 # 这里的dp[j]存的就是高度了!!
        for i in range(h):
            for j in range(w):
                dp[j] = dp[j] + 1 if matrix[i][j]=='1' else 0 # 这里不能写成dp[j]+=1

            ## leetcode 84     
            stack = [-1]
            for j in range(w):
                while stack[-1]!=-1 and dp[stack[-1]]>=dp[j]:#满足条件时计算的是j-1以及之前位置的最大面积! j相当于右边界index+1
                    cur_h = stack.pop()
                    res = max(res, dp[cur_h]*(j-stack[-1]-1))
                stack.append(j) # 计算完j-1的后再append(j)
            
            while stack[-1]!=-1:
                cur_h = stack.pop()
                res = max(res, dp[cur_h]*(w-stack[-1]-1))#因此这里就可以是w了, w是最大合法边界index+1
        return res
```