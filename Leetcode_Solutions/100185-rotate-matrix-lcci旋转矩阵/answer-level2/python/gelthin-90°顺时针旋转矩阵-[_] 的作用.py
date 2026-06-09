### 解题思路
老石春招华为诺亚面试题碰到此。
同习题 [48. 旋转图像](https://leetcode-cn.com/problems/rotate-image/)

#### 两步走的策略： 1. 先对矩阵进行转置，2.再对矩阵每一行，进行左右颠倒，就可以实现顺时针旋转 90°的效果
但这个怎么证明其正确性，以及如何推广到（逆时针）旋转其他度数，不是非常清楚。
官方题解给出了证明：考虑 (i,j) 位置上的值，最初为 matrix[i][j]， 转置后变为 matrix[j][i], 然后左右颠倒变为 matrix[j][n-i-1] 。

推广到其他度数，逆时针等，也是可以合理尝试，只需要找出 (i,j) 变化的最终目的，建议读题解 [48. 旋转图像 一次性交换](https://leetcode-cn.com/problems/rotate-image/solution/yi-ci-xing-jiao-huan-by-powcai/)

有点像 [189. 旋转数组](https://leetcode-cn.com/problems/rotate-array/) 两次 reverse 翻转的做法。

#### 一步到位的策略：
这个就需要构造比较精巧的方法。有点像 [189. 旋转数组](https://leetcode-cn.com/problems/rotate-array/) swap 一次到位的解法。

需要找特殊的规律，建议读题解 [48. 旋转图像 一次性交换](https://leetcode-cn.com/problems/rotate-image/solution/yi-ci-xing-jiao-huan-by-powcai/)

需要交换这4个位置的数：  (i, j), (j, n-1-i), (n-1-i, n-1-j), (n-1-j, i) 只是需要注意循环终止条件，进行一下分析。

#### 就地修改, matrix[i][:] 与 matrix[i] 的区别
见我之前的分析 [gelthin-解释为何要用 nums1[:]](https://leetcode-cn.com/problems/merge-sorted-array/solution/gelthin-gui-bing-pai-xu-by-gelthin/)
``` python3
for i in range(n):
    matrix[i][:] = matrix[i][::-1]  # 这里不可以用 matrix[i] = matrix[::-1]
```
因为需要就地修改， 使用 `matrix[i] = matrix[::-1]` 会使得， `matrix[i]` 指向了一个新的临时变量数组


### 代码

```python3
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # 很早之前看题解的规律，先 matrix -> matrix^T, 然后在每一行，左右颠倒
        N = len(matrix)
        if N <= 1:
            return
        
        for i in range(N):
            for j in range(i+1, N):
                matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
        
        for i in range(N):
            j1, j2 = 0, N-1
            while j1<j2:
                matrix[i][j1], matrix[i][j2] = matrix[i][j2], matrix[i][j1]
                j1 += 1
                j2 -= 1
```