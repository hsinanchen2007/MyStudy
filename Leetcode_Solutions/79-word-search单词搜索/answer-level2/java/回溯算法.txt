### 解题思路
执行用时 :4 ms, 在所有 Java 提交中击败了99.47%的用户
内存消耗 :42.8 MB, 在所有 Java 提交中击败了17.18%的用户

从找到的第一位开始，用回溯算法遍历所有的可能。

### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
		int h = board.length;
		int w = board[0].length;
		int p = 0;
		boolean res = false;
        char tmp;

		char[] words = word.toCharArray();
		int lenRest = words.length;

		if(h==0 && w==0){
			return false;
		}

		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(board[i][j]==words[0]){
                    tmp = board[i][j];
                    board[i][j] = '0';
					res = backtrack(board, words, i, j, p+1, lenRest-1, h, w);
					if(res){
						return true;
					}
                    board[i][j] = tmp;
				}
			}
		}

		return false;

    }

	private static boolean backtrack(char[][] board, char[] words, int i, int j,
										int p, int lenRest, int h, int w){
		if(lenRest==0){
			return true;
		}

		boolean res = false;
		char tmp;

		if(i-1>=0){
			if(board[i-1][j]==words[p]){
				tmp = board[i-1][j];
				board[i-1][j] = '0';
				res = backtrack(board, words, i-1, j, p+1, lenRest-1, h, w);
				if(res){return true;}
				board[i-1][j] = tmp;
			}
		}

		if(i+1<=h-1){
			if(board[i+1][j]==words[p]){
				tmp = board[i+1][j];
				board[i+1][j] = '0';
				res = backtrack(board, words, i+1, j, p+1, lenRest-1, h, w);
				if(res){return true;}
				board[i+1][j] = tmp;
			}
		}

		if(j-1>=0){
			if(board[i][j-1]==words[p]){
				tmp = board[i][j-1];
				board[i][j-1] = '0';
				res = backtrack(board, words, i, j-1, p+1, lenRest-1, h, w);
				if(res){return true;}
				board[i][j-1] = tmp;
			}
		}

		if(j+1<=w-1){
			if(board[i][j+1]==words[p]){
				tmp = board[i][j+1];
				board[i][j+1] = '0';
				res = backtrack(board, words, i, j+1, p+1, lenRest-1, h, w);
				if(res){return true;}
				board[i][j+1] = tmp;
			}
		}

		return false;
	}
}
```