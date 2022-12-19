Time: 20190905
Type: Medium

### 题目描述
给定一个方形整数数组 A，我们想要得到通过 A 的下降路径的最小和。

下降路径可以从第一行中的任何元素开始，并从每一行中选择一个元素。在下一行选择的元素和当前行所选元素最多相隔一列。


示例：

输入：
```python
[[1,2,3],
 [4,5,6],
 [7,8,9]]
```

输出：`12`
解释：
可能的下降路径有：

[1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
[2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
[3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]

和最小的下降路径是 [1,4,7]，所以答案是 12。


提示：

1 <= A.length == A[0].length <= 100
-100 <= A[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-falling-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


### 思路
本题的题眼也是“最小”，因此，想到用动态规划法。

且很容易感受到动态规划的状态比较好定义：

`f[i][j]`表示经过行标`i`和列标`j`元素时候的下降路径和，站在当前元素上回头考虑它可以从哪里过来，得出以下的递推式：

```python
f[i][j] = min(f[i-1][j-1], f[i-1][j], f[i-1][j+1])
```
需要注意在列号为`0`和`col - 1`时，右边三个元素只取其中两个。

### 代码

```python
class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        # f[i][j] = min(f[i-1][j], f[i-1][j-1], f[i-1][j+1])
        row, col = len(A), len(A[0])
        f = [[0] * row for _ in range(col)]
        
        for j in range(col):
            f[0][j] = A[0][j]
        
        for i in range(1, row):
            for j in range(col):
                if j == 0:
                    f[i][j] = min(f[i-1][j], f[i-1][j+1]) + A[i][j]
                elif j == col - 1:
                    f[i][j] = min(f[i-1][j], f[i-1][j-1]) + A[i][j]
                else:
                    f[i][j] = min(f[i-1][j], f[i-1][j-1], f[i-1][j+1]) + A[i][j]
        # print(f)
                    
        return min(f[row-1][:])
```
本题是可以直接在`A`上操作，不用开辟新的空间的，代码如下：

```python
class Solution:
    def minFallingPathSum(self, A: List[List[int]]) -> int:
        # f[i][j] = min(f[i-1][j], f[i-1][j-1], f[i-1][j+1])
        row, col = len(A), len(A[0])
        
        for i in range(1, row):
            for j in range(col):
                if j == 0:
                    A[i][j] += min(A[i-1][j], A[i-1][j+1])
                elif j == col - 1:
                    A[i][j] += min(A[i-1][j], A[i-1][j-1]) 
                else:
                    A[i][j] += min(A[i-1][j], A[i-1][j-1], A[i-1][j+1]) 
                    
        return min(A[row-1][:])
```

END.