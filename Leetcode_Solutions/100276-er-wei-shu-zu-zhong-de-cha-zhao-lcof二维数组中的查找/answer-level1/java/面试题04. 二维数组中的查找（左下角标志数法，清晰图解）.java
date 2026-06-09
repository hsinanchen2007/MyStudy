#### 解题思路：

> 若使用暴力法遍历矩阵 `matrix` ，则时间复杂度为 $O(N*M)$ 。暴力法未利用矩阵 **“从上到下递增、从左到右递增”** 的特点，显然不是最优解法。
> 本题解利用矩阵特点引入标志数，并通过标志数性质降低算法时间复杂度。

- **标志数引入：** 此类矩阵中左下角和右上角元素有特殊性，称为**标志数**。
  - **左下角元素：** 为所在**列最大**元素，所在**行最小**元素。
  - **右上角元素：** 为所在**行最大**元素，所在**列最小**元素。

- **标志数性质：** 将 `matrix` 中的**左下角元素**（标志数）记作 `flag` ，则有:
  1. 若 `flag > target` ，则 `target` 一定在 `flag` 所在行的上方，即 `flag` 所在行可被消去。
  2. 若 `flag < target` ，则 `target` 一定在 `flag` 所在列的右方，即 `flag` 所在列可被消去。
  - 本题解以左下角元素为例，同理，**右上角元素** 也具有行（列）消去的性质。

- **算法流程：** 根据以上性质，设计算法在每轮对比时消去一行（列）元素，以降低时间复杂度。
  1. 从矩阵 `matrix` 左下角元素（索引设为 `(i, j)` ）开始遍历，并与目标值对比：
     - 当 `matrix[i][j] > target` 时： 行索引向上移动一格（即 `i--`），即消去矩阵第 `i` 行元素；
     - 当 `matrix[i][j] < target` 时： 列索引向右移动一格（即 `j++`），即消去矩阵第 `j` 列元素；
     - 当 `matrix[i][j] == target` 时： 返回 $true$ 。
  2. 若行索引或列索引越界，则代表矩阵中无目标值，返回 $false$ 。

> **算法本质：** 每轮 `i` 或 `j` 移动后，相当于生成了“消去一行（列）的新矩阵”， 索引`(i,j)` 指向新矩阵的左下角元素（标志数），因此可重复使用以上性质消去行（列）。

#### 复杂度分析：

- 时间复杂度 $O(M+N)$ ：其中，$N$ 和 $M$ 分别为矩阵行数和列数，此算法最多循环 $M+N$ 次。
- 空间复杂度 $O(1)$ : `i`, `j` 指针使用常数大小额外空间。

<![Picture1.png](https://pic.leetcode-cn.com/443c0751fbc3ee40930f04231dcd03e3462243c6dbd3d77a72714c8273ecbe4a-Picture1.png),![Picture2.png](https://pic.leetcode-cn.com/23d65449566ff8f128938b41bb46a636dd417200b8a04ac9677731c475f862e1-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/f56c86b0762076bdbba4a2c5a6f9063027e2bd5f58b539fc408ad2676d4c0688-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/c2f130b827df860d03da2b8807a9b40204da1cb870a21f896f6e668b2abe58ac-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/db41c619cf43ace9482a132d93a8235520aa1fbb6a32c0eb58a8421bdc73fe50-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/83e1bf6b6b3cd3d088c666062f071a4fee75ded93519a8dd48112ea721f0229e-Picture6.png)>

#### 代码：

```python []
class Solution:
    def findNumberIn2DArray(self, matrix: List[List[int]], target: int) -> bool:
        i, j = len(matrix) - 1, 0
        while i >= 0 and j < len(matrix[0]):
            if matrix[i][j] > target: i -= 1
            elif matrix[i][j] < target: j += 1
            else: return True
        return False
```

```java []
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        int i = matrix.length - 1, j = 0;
        while(i >= 0 && j < matrix[0].length)
        {
            if(matrix[i][j] > target) i--;
            else if(matrix[i][j] < target) j++;
            else return true;
        }
        return false;
    }
}
```