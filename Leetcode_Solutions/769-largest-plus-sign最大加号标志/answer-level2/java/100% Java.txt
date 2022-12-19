### 解题思路
暴力+剪枝，开5个[N+2][N+2]大的数组。
一个用来初始化数组。
另外四个用来统计该点上下左右1的大小
        		left[i][j]=board[i][j]==1?(1+left[i][j-1]):0;		// 左
        		right[i][N-j+1]=board[i][N-j+1]==1?(1+right[i][N-j+2]):0;// 右
        		top[j][i]=board[j][i]==1?(1+top[j-1][i]):0;		// 上
        		bottom[N-j+1][i]=board[N-j+1][i]==1?(1+bottom[N-j+2][i]):0;	// 右
具体见代码
思路并不难
### 代码

```java
class Solution {
    // 764. 最大加号标志
    public int orderOfLargestPlusSign(int N, int[][] mines) {
        int[][] board = new int[N+2][N+2];
        for(int i = 1 ; i <= N ; i++){
        	Arrays.fill(board[i], 1);
        }
        int[][] left = new int[N+2][N+2];   // 记录 left[i][j]为从i，j开始左面连续1的个数
        int[][] right = new int[N+2][N+2];  // 记录right[i][j]为从i,j开始右面连续1的个数
        int[][] top = new int[N+2][N+2];
        int[][] bottom = new int[N+2][N+2];
        for(int i = 0 ; i < mines.length;i++){
        	board[mines[i][0]+1][mines[i][1]+1]=0;
        }
        for(int i = 0 ; i < N+2 ; i++){
        	board[i][0]=board[i][N+1]=0;
        }
//        for(int i = 0 ; i < board.length ; i++){
//        	for(int j = 0 ; j < board[0].length ; j++)
//        		System.out.print(board[i][j]+"  ");
//        	System.out.println();
//        }
        for(int i = 1 ; i <= N ; i++){
        	for(int j = 1 ; j <= N ; j++){
        		left[i][j]=board[i][j]==1?(1+left[i][j-1]):0;		// 左
        		right[i][N-j+1]=board[i][N-j+1]==1?(1+right[i][N-j+2]):0;// 右
        		top[j][i]=board[j][i]==1?(1+top[j-1][i]):0;		// 上
        		bottom[N-j+1][i]=board[N-j+1][i]==1?(1+bottom[N-j+2][i]):0;	// 右
        	}
        }
        int res = 0;
        for(int i = 1; i <= N ; i++){
        	for(int j = 1 ; j <=N ; j++){
        		if(left[i][j]>res && right[i][j]>res && top[i][j]>res && bottom[i][j]>res){
        			res=Math.min(Math.min(left[i][j], right[i][j]),Math.min(top[i][j], bottom[i][j]) );
        		}
        	}
        }
        return res;
    }
}
```