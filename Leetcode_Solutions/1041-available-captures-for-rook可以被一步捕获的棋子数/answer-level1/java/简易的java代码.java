### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board){
		int sum = 0;
		for(int i=0;i<board.length;i++){
			for(int j=0;j<board[0].length;j++){
				if(board[i][j] == 'R'){
					// 向上找
					for(int x=i;x>=0;x--){
						if(board[x][j] == 'B'){// 后续就算有p也会被挡住，所以此处break
							break;
						}
						if(board[x][j] == 'p'){
							sum++;
							break;// 因为如果后面还有p，则需要两步才能捕获，所以此处break
						}
					}
					// 向下找
					for(int x=i;x<board.length;x++){
						if(board[x][j] == 'B'){
							break;
						}
						if(board[x][j] == 'p'){
							sum++;
							break;
						}
					}
					// 向左找
					for(int y=j;y>=0;y--){
						if(board[i][y] == 'B'){
							break;
						}
						if(board[i][y] == 'p'){
							sum++;
							break;
						}
					}
					// 向右找
					for(int y=j;y<board[i].length;y++){
						if(board[i][y] == 'B'){
							break;
						}
						if(board[i][y] == 'p'){
							sum++;
							break;
						}
					}
					return sum;// 因为一张表中只有一个'r'，所以找完此元素的上下左右就返回sum
				}
			}
		}
		return 0;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/c77a7e39b19fdb3e733447bc0d523b8ca45750f56cb261ef6a9adfa1e7863c30-1.png)

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/74dd86143860027d82ee57f73960f22ce5ccd15f5a54be43bee24d5301111715-wechat.png)

