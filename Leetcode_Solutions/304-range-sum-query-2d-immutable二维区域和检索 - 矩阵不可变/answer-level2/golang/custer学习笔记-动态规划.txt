### 解题思路
s(i,j)表示下标(0,0)到下标(i-1,j-1)的子矩阵元素和。

也就是说对于左上角坐标是(0,0),右下角坐标是(i-1,j-1)的子矩阵。

将矩阵内所有元素加起来得到的就是s(i,j)

为了可以用上前缀和s(i,j)，我们需要利用左上角坐标是(0,0)的子矩阵，

因此我们可以先拿出一个包含中间子矩阵，并且左上角坐标是(0,0)的子矩阵。

即子矩阵(0,0,r2,c2)包含了子矩阵(r1,c1,r2,c2),并且还多出左边一个子矩阵和上面一个子矩阵。

于是我们要减去这两个部分的和。左边的子矩阵左上角坐标仍然是(0,0),

右下角的行坐标是r2,列坐标是c1-1,于是我们可以减去f(0,0,r2,c1-1).

上面的子矩阵左上角坐标同样是(0,0),右下的行坐标是(r1-1),列坐标是c2，

于是我们要减去f(0,0,r1-1,c2),左边的子矩阵和上面的子矩阵，

有一个重叠部分被减去了两次，因此我们还要将这个重叠的子矩阵加回来一次。

这个重叠的子矩阵左上角是(0,0),右下角的行坐标比r1少1，列坐标比c1少1.

因此要加回来的部分是f(0,0,r1-1,c1-1).

这样我们就把要计算的子矩阵表示成了左上角坐标都是(0,0)的四个子矩阵之间的运算。

`f(r1,c1,r2,c2) = f(0,0,r2,c2) - f(0,0,r2,c1-1) - f(0,0,r1-1,c2) + f(0,0,r1-1,c1-1)`

**s(i,j)表示下标(0,0)到下标(i-1,j-1)的子矩阵元素和。**

这四个子矩阵元素和都可以换成前缀和s(i,j)来表示。

	* f(0,0,r2,c2)        -> s(r2+1,c2+1)
	* f(0,0,r2,c1-1)    -> s(r2+1,c1)
	* f(0,0,r1-1,c2)    -> s(r1, c2-1)
	* f(0,0,r1-1,c1-1) -> s(r1,c1)

`f(r1,c1,r2,c2) = s(r2+1,c2+1) - s(r2+1,c1) - s(r1,c2+1) + s(r1,c1)`

这样一来，只要我们把所有的前缀和都计算好，就可以用O(1)的时间计算出任意子矩阵内的元素和。
接下来，我们看一下怎么计算前缀和s(i,j)。

我们先把s(i,j)对应的子矩阵画出来。这个子矩阵的左上角是(0,0)，右下角坐标是(i-1,j-1)。

子矩阵内所有元素之和就是s(i,j)。我们把右下角数字记为p。左边的子矩阵的右下角坐标是(i-1,j-2)。

p左边这个子矩阵对应的前缀和是s(i,j-1),同样的p上面有个子矩阵，右下角坐标是(i-2,j-1)。

p上边这个子矩阵对应的前缀和是s(i-1,j),为了得到s(i,j)我们可以把这两个部分加起来。

加起来的这两个子矩阵，有一部分重叠，我们把它标记出来。

由于重叠的子矩阵多加了一次，因此我们要把它减去一份。它的右下角坐标是(i-2,j-2)。

因此对应的前缀和是s(i-1,j-1)，于是我们减掉一份s(i-1,j-1)。

最后s(i,j)就差p点的这个数字，于是把它加起来，即加上a(i-1,j-1)，a是给我们的二维矩阵。

有了这个递推式，我们只需要遍历i和j就可以吧所有的前缀和都提前计算出来。

而前面已经说了，只要提前计算好所有的前缀和就可以用常量时间计算出任意子矩阵内的元素和。

`s(i,j) = s(i,j-1) + s(i-1,j) - s(i-1,j-1) + a(i-1,j-1)`

### 代码

```golang
type NumMatrix struct {
  PrefixSum [][]int // 保存二维矩阵的所有前缀和
}

func Constructor(matrix [][]int) NumMatrix {
  // 首先处理边界情况
  if matrix == nil || len(matrix) == 0 || matrix[0] == nil || len(matrix[0]) == 0 {
    prefixSum := make([][]int, 1) // 把前缀和定义为1x1的二维矩阵
    for i := range prefixSum {
      prefixSum[i] = make([]int, 1)
    }
    return NumMatrix{PrefixSum: prefixSum}
  }
  // 否则把矩阵的两个维度取出,分别赋值给m和n,方便使用
  m, n := len(matrix), len(matrix[0])
  // 并把前缀和数组定义为 m+1 * n+1 的二维数组
  prefixSum := make([][]int, m+1)
  for i := range prefixSum {
    prefixSum[i] = make([]int, n+1)
  }
  for i := 1; i <= m; i++ {
    for j := 1; j <= n; j++ {
      prefixSum[i][j] = prefixSum[i][j-1] + prefixSum[i-1][j] - prefixSum[i-1][j-1] + matrix[i-1][j-1]
    }
  }
  return NumMatrix{PrefixSum: prefixSum}
}

// 子矩阵求和
func (this *NumMatrix) SumRegion(row1 int, col1 int, row2 int, col2 int) int {
  // 坐标row1,col1到坐标row2,col2子矩阵内的元素和
  return this.PrefixSum[row2+1][col2+1] - this.PrefixSum[row2+1][col1] - this.PrefixSum[row1][col2+1] + this.PrefixSum[row1][col1]
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
```