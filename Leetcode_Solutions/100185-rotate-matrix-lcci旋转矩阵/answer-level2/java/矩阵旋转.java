### 解题思路
顺时针旋转的时候抓住其中的四个对应点的位置坐标分别为(i,j),(n-1-j,i),(n-1-i,n-1-j),(j,n-1-i)

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n=matrix.length;
		for(int i=0;i<n/2;i++){
			for(int j=i;j<n-1-i;j++){
				int temp=matrix[i][j];
				matrix[i][j]=matrix[n-1-j][i];
				matrix[n-1-j][i]=matrix[n-1-i][n-1-j];
				matrix[n-1-i][n-1-j]=matrix[j][n-1-i];
				matrix[j][n-1-i]=temp;
			}
		}
    }
}
```