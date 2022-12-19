### 定义一个二维数组dp[i][j]表示坐标为(i,j)的点到底部的最小距离和
```
 //从顶点到最底部的最小距离和等于它的下一行邻接点到底部的最小距离和加上它自身；定义dp[i][j]表示坐标为(i,j)的点到底部的最小距离和
 		int row=triangle.size();
 		int column=triangle.get(row-1).size();//最后一行数最多，作为数组列数来用
 		int dp[][]=new int[row][column];
 		for(int i=0;i<column;i++)
 			dp[row-1][i]=triangle.get(row-1).get(i);//最后一行到底部的距离就等于它自身的值
 		for(int i=row-2;i>=0;i--) {
 			for(int j=0;j<=i;j++) {
 				dp[i][j]=Math.min(dp[i+1][j],dp[i+1][j+1])+triangle.get(i).get(j);
 			}
 		}
 		return dp[0][0];
```


### 空间优化为一维

```   
//空间优化： 每次计算一层(i,j)位置的数到底部的最小距离和时，当前层只跟它的下一层有关系，所以我们只用保留下一层的结果
		//就可以，用一维数组，一直更新这个一维数组就可以
		int row=triangle.size();
		int column=triangle.get(row-1).size();//最后一行数最多，作为数组列数来用
		int dp[]=new int[column];
		for(int i=0;i<column;i++)
			dp[i]=triangle.get(row-1).get(i);//最后一行到底部的距离就等于它自身的值
		for(int i=row-2;i>=0;i--) {
			for(int j=0;j<=i;j++) {
				dp[j]=Math.min(dp[j],dp[j+1])+triangle.get(i).get(j);
			}
		}
		return dp[0];
```

### 空间再次优化：原地修改
```	
		//空间再次优化，我们其实都不用创建新数组，直接用当前三角形数组的最后一行，在最后一行更新数据即可：
		//因为最后一行到底部距离就是自身值，除了第二行会用到，而且第二行的(i,j)位置的数算出来后，
		//最后一行的(i+1,j)位置的数就将不再会用到
		int row=triangle.size();
		for(int i=row-2;i>=0;i--) {
			for(int j=0;j<=i;j++) {
				int temp=Math.min(triangle.get(row-1).get(j),triangle.get(row-1).get(j+1))+triangle.get(i).get(j);
				triangle.get(row-1).set(j, temp);//更新最后一行j位置的值
			}
		}
		return triangle.get(row-1).get(0);
```