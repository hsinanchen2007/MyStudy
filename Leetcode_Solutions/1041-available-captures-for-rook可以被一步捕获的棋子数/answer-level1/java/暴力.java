### 解题思路
暴力遍历
先找到车的位置
然后分四个方向遍历卒。

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
         int index1 = 0,index2 = 0;
	  for(int i=0;i<8;i++){
		  for(int j=0;j<8;j++){
			  if(board[i][j] == 'R'){
				  index1 = i;
				  index2 = j;
				   break;
			  }
		  }
	  }
	  System.out.println(index1 + "  " + index2);
	  int sum = 0;
	  for(int i=index2+1;i<8;i++){
		  if(board[index1][i]=='p'){
			  sum = sum + 1;
			  break;
		  }
		  if(board[index1][i]=='B'){
			  break;
		  }
	  }
	  for(int i=index2-1;i>=0;i--){
		  if(board[index1][i]=='p'){
			  sum = sum + 1;
			  break;
		  }
		  if(board[index1][i]=='B'){
			  break;
		  }
	  }
	  for(int j=index1+1;j<8;j++){
		  if(board[j][index2] == 'p'){
			  sum = sum + 1;
			  break;
		  }
		  if(board[j][index2] == 'B'){
			  break;
		  }
	  }
	  for(int j=index1-1;j>=0;j--){
		  if(board[j][index2] == 'p'){
			  sum = sum + 1;
			  break;
		  }
		  if(board[j][index2] == 'B'){
			  break;
		  }
	  }
	  return sum;
    }
}
```