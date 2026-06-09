### 解题思路
1.定义cnt记录到达格子的次数,定义visit数组记录当前格子是否进入过
2.从0,0坐标开始移动递归判断当前格子是否符合行列坐标位数之和小于k,符合则visit[i][j] = 1,并且cnt++
3.返回cnt

### 代码

```java
class Solution {
    int cnt = 0;
	public int movingCount(int m, int n, int k) {

		int[][] visit = new int[m][n];
		movingCount(0,0,m,n,visit,k);
		return cnt;
    }

	private void movingCount(int i, int j,int row,int col, int[][] visit, int k) {
		if(i<0||i>=row||j<0||j>=col||visit[i][j]==1||compare(k,i,j)){
			return ;
		}
		visit[i][j] = 1;
		cnt++;
		movingCount(i-1, j,row,col, visit, k);
		movingCount(i+1, j,row,col, visit, k);
		movingCount(i, j-1,row,col, visit, k);
		movingCount(i, j+1,row,col, visit, k);
		
	}

	public boolean compare(int threshold,int row,int col){
        int sum = 0;
        while(row!=0){
            int num = row%10;
            sum+=num;
            row/=10;
        }
        while(col!=0){
            int num = col%10;
            sum+=num;
            col/=10;
        }
        return sum>threshold;
    }
}
```