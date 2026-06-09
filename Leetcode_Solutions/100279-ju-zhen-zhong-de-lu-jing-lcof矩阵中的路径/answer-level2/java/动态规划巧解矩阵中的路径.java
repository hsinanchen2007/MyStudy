### 具体思路注释在代码中
### 代码

```java
class Solution {
    public boolean exist(char[][] board, String word) {
        int index = 0;//作为字符串的索引
		boolean ans = false;
		//用于标记数组元素是否为被选中的字符串中的字符
		boolean[][] flag = new  boolean[board.length][board[0].length];
		//遍历数组，找到字符数组中与字符串首字符相同的元素，进行递归匹配字符
		for(int i = 0;i<board.length;i++) {
			for(int j = 0;j<board[0].length;j++) {
				if(board[i][j] == word.charAt(index)) {
					 ans = find(i,j,board,index,word,flag);
					//只要返回true，就结束查找
					 if(ans == true) return true;
				}
			}
		}
		return ans;
    }
    private boolean find(int i, int j, char[][] board, int index, String word, boolean[][] flag) {
		//标记当前元素board[i][j]被选中
		flag[i][j] = true;
		//先默认当前元素未能符合要求被选中
		boolean tempFlag = false;
		//结束函数的一个条件
		if(index >= word.length()-1) return true;
		/*
		 * 1、j+1 < board[0].length：避免数组越界
		 * 2、board[i][j+1] == word.charAt(index+1)：决定是否进入下一步递归匹配字符
		 * 3、flag[i][j+1] == false：防止下一个节点是之前走过的，题目规则要求不允许
		 * 4、tempFlag == false：保证找到了能匹配的整个字符串后，就不继续找其他方向的；
		 *    同时也保证没找到了能匹配的整个字符串，还能继续找其他方向的
		 */
		if(j+1 < board[0].length && board[i][j+1] == word.charAt(index+1) && flag[i][j+1] == false) {
			tempFlag = find(i,j+1,board,index+1,word,flag);
		}
		if(tempFlag == false && i+1 < board.length && board[i+1][j] == word.charAt(index+1) && flag[i+1][j] == false) {
			tempFlag = find(i+1,j,board,index+1,word,flag);
		}
		if(tempFlag == false && j-1 >= 0 && board[i][j-1] == word.charAt(index+1) && flag[i][j-1] == false) {
			tempFlag = find(i,j-1,board,index+1,word,flag);
		}
		if(tempFlag == false && i-1 >= 0 && board[i-1][j] == word.charAt(index+1) && flag[i-1][j] == false) {
			tempFlag = find(i-1,j,board,index+1,word,flag);
		}
		//在递归之后发现没能匹配整个字符串，则将当前设置为未被选中状态
		if(tempFlag == false) {
			flag[i][j] = false;
		}
		return tempFlag;
	}
}
```