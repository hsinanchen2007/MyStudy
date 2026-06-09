### 解题思路
首先找出规律，最终的结果{7,4,1}  {8,5,2} {9,6,3}的规律如下：

元素   原位置    目标位置
7      (2,0)     (0,0)
4      (1,0)     (0,1)
1      (0,0)     (0,2)

8      (2,1)     (1,0)
5      (1,1)     (1,1)
2      (0,1)     (1,2)

9      (2,2)     (2,0)
6      (1,2)     (2,1)
3      (0,2)     (2,2)
 
如上规律理清后，就简单了；


### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
int[][] newMatrix = new int[matrix.length][matrix[0].length];

		int n = 0;

		for (int i = matrix.length - 1; i >= 0; i--) {
			for (int j = 0; j < matrix[matrix.length - 1].length; j++) {
				// System.out.println(matrix[i][j]);
				newMatrix[j][n] = matrix[i][j];
			}
			++n;
		}

		for (int i = 0; i < newMatrix.length; i++) {

			matrix[i] = newMatrix[i].clone();
		}
    }
}
```