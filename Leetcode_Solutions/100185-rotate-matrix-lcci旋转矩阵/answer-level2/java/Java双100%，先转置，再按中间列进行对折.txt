### 解题思路
矩阵旋转90度，可以拆解为先转置，再按矩阵的中间一列进行对折，即可得到旋转90度的结果。
举个例子：
原矩阵为：
  [1,2,3]
  [4,5,6]
  [7,8,9]

转置之后，即按斜对角线进行数据交换后的结果为：
  [1,4,7]
  [2,5,8]
  [3,6,9]

矩阵再根据中间列进行对折，即中间列两边元素进行交换，得到：
  [7,4,1]
  [8,5,2]
  [9,6,3]

即为旋转90度后的结果，也就是最终答案。

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
		int n = matrix.length;
		//矩阵转置，即按斜对角线进行数据交换
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}

		//矩阵根据中间列进行对折，得到最终结果
		for(int i=0;i<n;i++){
			for(int j=0;j<n/2;j++){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[i][n-j-1];
				matrix[i][n-j-1] = temp;
			}
		}
    }
}
```