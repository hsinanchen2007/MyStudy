思路：用一个和 board 等大的二维数组 score 来做被遍历过的标记，每一块字母 O 区域用不同的数字标记。设置两个深度优先函数，一个深度优先函数用来判断一块字母 O 区域是否可以转换为 X，如果可以 flag 为 true ，用另一个深度优先函数转换。如果不可以 flag 为 false ，不转换。详情看代码。         
**c++ 版代码:**     
```
class Solution {
public:
    void solve(vector<vector<char> >& board) {    
    	if(board.size() == 0)
        	return;
        bool flag = true;                        // 标志位，判断一块字母 O 区域能否变为字母 X   
    	int colCount = board[0].size() - 1;      // 列的索引范围 
    	int rowCount = board.size() - 1;         // 行的索引范围 
    	vector<vector<int> >score;                     // 定义一个和 board 同样大的矩阵来记录 board 中已经被遍历过的 O 
    	vector<int> fillValue(board[0].size(),0);        // 定义一个一维的 vector 并初始化为 0 ，用来把 二维score 初始化为 0 
        for(int i = 0; i < board.size(); i++){        // 初始化 score,都为 0  
    		score.push_back(fillValue);
	    }
	    for(int i = 0; i < board.size(); i++ ){       // 从上到下 
	    	for(int j = 0; j < board[i].size(); j++){ // 从做到右 
	    	    flag = true; // 每判断一次都把 flag 重置为 true 
	    		if(board[i][j] == 'O' && score[i][j] == 0){               // 寻找到了字母 'O'，开始深度优先遍历 
	    		DFS_Judge(board, score, i,  j, rowCount , colCount, flag);  // 找到一块字母 O 区域，用 count 所代表的的数字标记 
	    		// 如果 flag = true 则证明以 (i,j) 为起点深度优先遍历的字母 O 区域可以转换为字母 X，用 DFS_Turn_X()函数转换为 X 
				if(flag)  DFS_Turn_X(board, i,  j, rowCount , colCount);    
				
				}
			}
		}
	
	    
    }
    /**
       这个深度优先函数判断一块字母 O区域是否可以把 O 转换成 X，如果可以则 flag = true,反之则   flag =false 
    */
    void DFS_Judge(vector<vector<char> >& board, vector<vector<int> >& score, int sr, int sc,int rowCount ,int colCount,bool &flag){
    	if(score[sr][sc] == 1 || board[sr][sc] == 'X'){  // 递归出口，如果一个位置已经被遍历过， score[sr][sc] == 1 代表被遍历过，为 0 则没有 
    		return;                                      // 或者值为 'X'，则停止遍历 
		}
		if(board[sr][sc] == 'O' && score[sr][sc] == 0 ){
			score[sr][sc] = 1;                         // 标记为 1 ，代表这个位置已经遍历过了 
		} 
		if(sr == 0 || sc == 0 || sr == rowCount || sc == colCount){ // 如果位置 (sr,sc) 数组的边界上 
			flag = false;                        // 标志位为 false 
			//return;                              // 接收判断 
		}
		if(sr-1 >= 0){                           // 如果向上数组还没有越界
			DFS_Judge(board, score, sr-1,  sc,  rowCount , colCount, flag); // 向上查找 O 
		}
		if(sc+1 <= colCount){                  // 如果向右数组还没有越界
			DFS_Judge(board, score,  sr,  sc+1, rowCount , colCount, flag); // 向右查找 O 
		}
		if(sr+1 <= rowCount){                 // 如果向下数组还没有越界
			DFS_Judge(board,  score, sr+1,  sc, rowCount , colCount, flag); // 向下查找 O 
		} 
		if(sc-1 >= 0){                       // 如果向左数组还没有越界
			DFS_Judge(board, score, sr,  sc-1,  rowCount , colCount, flag); // 向左查找 O 
		} 	
	}
	 /**
       这个深度优先函数判断一块字母 O区域是把 O 转换成 X
    */
	void DFS_Turn_X(vector<vector<char> >& board, int sr, int sc,int rowCount ,int colCount){ 
		if(board[sr][sc] == 'X'){  // 递归出口，如果一个位置值为 'X'，则停止遍历 
    		return;                                     
		}
		if(board[sr][sc] == 'O'){
			board[sr][sc] = 'X';                    // 把 O 转换为 X 
		} 
		if(sr-1 >= 0){                           // 如果向上数组还没有越界
			DFS_Turn_X(board,  sr-1,  sc, rowCount , colCount); // 向上查找 O 
		}
		if(sc+1 <= colCount){                  // 如果向右数组还没有越界
			DFS_Turn_X(board,  sr,  sc+1,rowCount , colCount); // 向右查找 O 
		}
		if(sr+1 <= rowCount){                 // 如果向下数组还没有越界
			DFS_Turn_X(board,  sr+1,  sc, rowCount , colCount); // 向下查找 O 
		} 
		if(sc-1 >= 0){                       // 如果向左数组还没有越界
			DFS_Turn_X(board,  sr,  sc-1, rowCount , colCount); // 向左查找 O 
		} 	
		
	}
};
```
**java 版代码:**  
```
class Solution {
   public void solve(char[][] board) {
		if(board.length == 0) {             // 如果数组为空则结束
			return;
		}
		boolean  flag[] = {true};           // 定义一个标准位,在 Java 中数组传递的是引用，相等于 C++ 中变量的引用传递                      
		int rowCount = board.length - 1;    // 这是行的索引范围 
		int colCount = board[0].length - 1; // 这是列的索引范围
		// 定义一个和 board 等大的整型数组做记录，Java 数组中不用初始化，默认为 0
		int score[][] = new int[board.length][board[0].length]; 
		for(int i = 0; i < board.length; i++) {
			for(int j = 0; j <board[0].length; j++) {
				flag[0] = true;                  // 每进行一个位置的判断前都把 标准位值设为 true
				// 如果一个位置值为 O，并且score[i][j] == 0,说明该位置没有判断过，进行判断；反之则判断
				if(board[i][j] == 'O' && score[i][j] == 0) {  
					DFS_Judge(board, score, i,  j, rowCount , colCount, flag);  // 找到一块字母 O 区域，用 count 所代表的的数字标记 
		    		// 如果 flag = true 则证明以 (i,j) 为起点深度优先遍历的字母 O 区域可以转换为字母 X，用 DFS_Turn_X()函数转换为 X 
					if(flag[0])  DFS_Turn_X(board, i,  j, rowCount , colCount);   
				}
			}
		}
        
    }
	/**
    这个深度优先函数判断一块字母 O区域是否可以把 O 转换成 X，如果可以则 flag = true,反之则   flag =false 
 */
  public  void DFS_Judge(char[][]  board, int[][] score, int sr, int sc,int rowCount ,int colCount,boolean[] flag){
 	if(score[sr][sc] == 1 || board[sr][sc] == 'X'){  // 递归出口，如果一个位置已经被遍历过， score[sr][sc] == 1 代表被遍历过，为 0 则没有 
 		return;                                      // 或者值为 'X'，则停止遍历 
		}
		if(board[sr][sc] == 'O' && score[sr][sc] == 0 ){
			score[sr][sc] = 1;                         // 标记为 1 ，代表这个位置已经遍历过了 
		} 
		if(sr == 0 || sc == 0 || sr == rowCount || sc == colCount){ // 如果位置 (sr,sc) 数组的边界上 
			flag[0] = false;                        // 标志位为 false 
			//return;                              // 接收判断 
		}
		if(sr-1 >= 0){                           // 如果向上数组还没有越界
			DFS_Judge(board, score, sr-1,  sc,  rowCount , colCount, flag); // 向上查找 O 
		}
		if(sc+1 <= colCount){                  // 如果向右数组还没有越界
			DFS_Judge(board, score,  sr,  sc+1, rowCount , colCount, flag); // 向右查找 O 
		}
		if(sr+1 <= rowCount){                 // 如果向下数组还没有越界
			DFS_Judge(board,  score, sr+1,  sc, rowCount , colCount, flag); // 向下查找 O 
		} 
		if(sc-1 >= 0){                       // 如果向左数组还没有越界
			DFS_Judge(board, score, sr,  sc-1,  rowCount , colCount, flag); // 向左查找 O 
		} 	
	}
	 /**
    这个深度优先函数判断一块字母 O区域是把 O 转换成 X
 */
	public void DFS_Turn_X(char[][]  board, int sr, int sc,int rowCount ,int colCount){ 
		if(board[sr][sc] == 'X'){  // 递归出口，如果一个位置值为 'X'，则停止遍历 
 		return;                                     
		}
		if(board[sr][sc] == 'O'){
			board[sr][sc] = 'X';                    // 把 O 转换为 X 
		} 
		if(sr-1 >= 0){                           // 如果向上数组还没有越界
			DFS_Turn_X(board,  sr-1,  sc, rowCount , colCount); // 向上查找 O 
		}
		if(sc+1 <= colCount){                  // 如果向右数组还没有越界
			DFS_Turn_X(board,  sr,  sc+1,rowCount , colCount); // 向右查找 O 
		}
		if(sr+1 <= rowCount){                 // 如果向下数组还没有越界
			DFS_Turn_X(board,  sr+1,  sc, rowCount , colCount); // 向下查找 O 
		} 
		if(sc-1 >= 0){                       // 如果向左数组还没有越界
			DFS_Turn_X(board,  sr,  sc-1, rowCount , colCount); // 向左查找 O 
		} 			
	}
}
```
