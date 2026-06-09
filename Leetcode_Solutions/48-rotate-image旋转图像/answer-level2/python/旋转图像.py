#### 方法 1 ：转置加翻转

最直接的想法是先转置矩阵，然后翻转每一行。这个简单的方法已经能达到最优的时间复杂度$O(N^2)$。

```Java [Solution 2]
class Solution {
  public void rotate(int[][] matrix) {
    int n = matrix.length;

    // transpose matrix
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int tmp = matrix[j][i];
        matrix[j][i] = matrix[i][j];
        matrix[i][j] = tmp;
      }
    }
    // reverse each row
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n / 2; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[i][n - j - 1];
        matrix[i][n - j - 1] = tmp;
      }
    }
  }
}
```

```Python [Solution 2]
class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix[0])        
        # transpose matrix
        for i in range(n):
            for j in range(i, n):
                matrix[j][i], matrix[i][j] = matrix[i][j], matrix[j][i] 
        
        # reverse each row
        for i in range(n):
            matrix[i].reverse()
```

* 时间复杂度：$O(N^2)$. 
* 空间复杂度：$O(1)$ 由于旋转操作是 *就地* 完成的。
<br />
<br />

---
#### 方法 2 ：旋转四个矩形

**直观想法**

方法 1 使用了两次矩阵操作，但是有只使用一次操作的方法完成旋转。

为了实现这一点，我们来研究每个元素在旋转的过程中如何移动。

![48_angles.png](https://pic.leetcode-cn.com/12605efb60d2efc64e6ecfcf6562a98a49acb3ce696b0c1ad3da46ab8977fa16-48_angles.png){:width="300px"}


这提供给我们了一个思路，将给定的矩阵分成四个矩形并且将原问题划归为旋转这些矩形的问题。


![48_rectangles.png](https://pic.leetcode-cn.com/7a684b207a95188ff6450e4724d6ee8bdf425fc483775a8e30082ed25060dac1-48_rectangles.png){:width="300px"}


现在的解法很直接 - 可以在第一个矩形中移动元素并且在 长度为 `4` 个元素的临时列表中移动它们。

<![image.png](https://pic.leetcode-cn.com/72f9aff037ca0f598e76d5f1fdb80be699dbc651bb7ae98c6f8fab75446f4ec0-image.png),![image.png](https://pic.leetcode-cn.com/d2b8312ed463bceb9ac3feb88e00c70abc4edc02c55ade3fea4723e757e269d9-image.png),![image.png](https://pic.leetcode-cn.com/dc9a6b302b2f980a834ec41ca20b9c5e33e616f176517922573eca3a3a5e4cf4-image.png),![image.png](https://pic.leetcode-cn.com/0a690b4158ebe5f63b7362046ef64fc7963bcbec9367e2538ae3a4c12c33f21f-image.png),![image.png](https://pic.leetcode-cn.com/dbe1585333c8ccb989b62c8c0a6bb672f309724967af92119ef949d81bbeebc4-image.png),![image.png](https://pic.leetcode-cn.com/a314b77e71329bdb7ade17f0a1a9aa29c347517c55f1a1731a6c0cd51e3606a3-image.png)>

**代码**

```Java [Solution 2]
class Solution {
  public void rotate(int[][] matrix) {
    int n = matrix.length;
    for (int i = 0; i < n / 2 + n % 2; i++) {
      for (int j = 0; j < n / 2; j++) {
        int[] tmp = new int[4];
        int row = i;
        int col = j;
        for (int k = 0; k < 4; k++) {
          tmp[k] = matrix[row][col];
          int x = row;
          row = col;
          col = n - 1 - x;
        }
        for (int k = 0; k < 4; k++) {
          matrix[row][col] = tmp[(k + 3) % 4];
          int x = row;
          row = col;
          col = n - 1 - x;
        }
      }
    }
  }
}
```

```Python [Solution 2]
class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix[0])
        for i in range(n // 2 + n % 2):
            for j in range(n // 2):
                tmp = [0] * 4
                row, col = i, j
                # store 4 elements in tmp
                for k in range(4):
                    tmp[k] = matrix[row][col]
                    row, col = col, n - 1 - row
                # rotate 4 elements   
                for k in range(4):
                    matrix[row][col] = tmp[(k - 1) % 4]
                    row, col = col, n - 1 - row
```

**复杂度分析**

* 时间复杂度：$O(N^2)$ 是两重循环的复杂度。
* 空间复杂度：$O(1)$ 由于我们在一次循环中的操作是 *就地* 完成的，并且我们只用了长度为 `4` 的临时列表做辅助。

<br />

---
#### 方法 3：在单次循环中旋转 4 个矩形

该想法和方法 2 相同，但是所有的操作可以在单次循环内完成并且这是更精简的方法。

```Java [Solution 2]
class Solution {
  public void rotate(int[][] matrix) {
    int n = matrix.length;
    for (int i = 0; i < (n + 1) / 2; i ++) {
      for (int j = 0; j < n / 2; j++) {
        int temp = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
        matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i];
        matrix[j][n - 1 - i] = matrix[i][j];
        matrix[i][j] = temp;
      }
    }
  }
}
```

```Python [Solution 2]
class Solution:
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix[0])        
        for i in range(n // 2 + n % 2):
            for j in range(n // 2):
                tmp = matrix[n - 1 - j][i]
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1]
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i]
                matrix[j][n - 1 - i] = matrix[i][j]
                matrix[i][j] = tmp
```

* 时间复杂度：$O(N^2)$ 是两重循环的复杂度。
* 空间复杂度：$O(1)$ 由于旋转操作是 *就地* 完成的。
