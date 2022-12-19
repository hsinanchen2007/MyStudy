### 解题思路
主要思路是遍历每一个元素，检查周围8个元素是活细胞的个数。由于是同步更新，需要复制一个二维数组，保持其中的一个不变，修改另外一个。在检查周围8个元素的时候，也可以通过遍历，从而减少多个if条件的判断。简化代码的书写。

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows=board.size();
        int cols=board[0].size();
       vector<vector<int> >copyBoard(rows, vector<int>(cols, 0));
       for (int i=0;i<rows;i++){//赋值数组
          for( int j=0;j<cols;j++){
              copyBoard[i][j]=board[i][j];
             // cout<<copyBoard[i][j]<<" ";
          }
         // cout<<endl;
       }
		
        for(int i=0;i<board.size();i++){
		for (int j=0;j<board[i].size();j++){
			int cnt=0;
			//这里用于获取周围的细胞状态，统计活细胞的个数
				for(int m=i-1;m<=i+1;m++){
					for (int n=j-1;n<=j+1;n++){
						if(m>=0&&m<board.size()&&n>=0&&n<board[i].size()){
							if(m==i&&n==j) continue;
							if(board[m][n]==1) cnt++;
						} 
					}
				}

			if(board[i][j]==0){//死细胞
				if(cnt==3) copyBoard[i][j]=1;
			}else{//活细胞
				if(cnt<2) copyBoard[i][j]=0;
				else if(cnt==2||cnt==3) copyBoard[i][j]=1;
				else copyBoard[i][j]=0;
			}
		}
        
        
	}
    // for(int i=0;i<rows;i++){
        //     for (int j=0;j<cols;j++)
        //     cout<<copyBoard[i][j]<<" ";
        //     cout<<endl;
        // }
        board=copyBoard;
    }
};
```