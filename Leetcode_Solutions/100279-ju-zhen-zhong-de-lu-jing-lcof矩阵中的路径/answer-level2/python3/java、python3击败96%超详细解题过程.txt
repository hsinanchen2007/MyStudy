## 解题分析
这道题，只能使用暴力DFS+剪枝来做，就是依次的遍历二位矩阵上面的所有节点，如果和给定的单词第一个字母匹配，那么我们就从这个节点开始，依次看他的上下左右的节点是不是和单词的第二个字母匹配，一旦有一个不匹配，后面的就不用比较了，直接查看二位矩阵的下一个节点，如果一直匹配到了单词的最后一个字母都相等的话，那就是已经有匹配的了，就可以终止遍历二位矩阵，直接返回True；如果所有节点都查看完毕，还是没有整体匹配的，就是整个二位矩阵都没有匹配的，返回False；

值得一提的是，不允许重复的利用节点，我们可以在判断完当前的节点等于单词上的某个字母之后，把这个节点的值做一个修改，等到下面的节点遍历返回结果的时候再给修改过来；
## 代码
- java实现

	```java
	class Solution {
	    public boolean exist(char[][] board, String word) {
	        if (Objects.isNull(board) || board.length == 0) {
	            return false;
	        }
	        char[] chars = word.toCharArray();
	        // 依次遍历二维矩阵的所有节点
	        for (int i = 0; i < board.length; i++) {
	            for (int j = 0; j < board[0].length; j++) {
	                if (dfs(board,chars,i,j,0)) {
	                    // 剪枝，已经找到，没有必要再往下继续
	                    return true;
	                }
	            }
	        }
	        return false;
	    }
	
	    public boolean dfs(char[][] board,char[] words,int line,int row,int index) {
	        // 剪枝
	        if (line >= board.length || row >= board[0].length || line < 0 || row < 0 || board[line][row] != words[index]) {
	            return false;
	        }
	        // 单词的最后一个字母也匹配上了,整体匹配完成
	        if (index == words.length - 1) {
	            return true;
	        }
	        // 已经匹配上的字母不能重复匹配，暂时修改节点的值
	        char temp = board[line][row];
	        board[line][row] = '/';
	        boolean ifExist = dfs(board,words,line + 1,row,index + 1) || dfs(board,words,line - 1,row,index + 1)
	                || dfs(board,words,line,row + 1,index + 1) || dfs(board,words,line,row - 1,index + 1);
	        // 还原节点上的值，以免影响下面的匹配
	        board[line][row] = temp;
	        // 返回这个节点开始的整体匹配结果 
	        return ifExist;
	    }
	}
	```

- python实现

	```python3
	class Solution:
	    def exist(self, board: List[List[str]], word: str) -> bool:
	        if board is None or len(board) == 0:
	            return False
	        words = list(word)
	        for i in range(len(board)):
	            for j in range(len(board[0])):
	                if self.dfs(board, words, i, j, 0):
	                    return True
	        return False
	
	    def dfs(self, board, words, i, j, index):
	        if i >= len(board) or i < 0 or j >= len(board[0]) or j < 0 or board[i][j] != words[index]:
	            return False
	        if index == len(words) - 1:
	            return True
	        temp = board[i][j]
	        board[i][j] = "1"
	        if_exist = self.dfs(board, words, i, j - 1, index + 1) or self.dfs(board, words, i, j + 1, index + 1) or self.dfs(board, words, i + 1, j, index + 1) or self.dfs(board, words, i - 1, j, index + 1)
	        board[i][j] = temp
	        return if_exist
	```