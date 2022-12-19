### 解题思路
# *N皇后很有趣喔，很有味道*

### 代码

```java
class Solution {
   List<HashSet<Character>> rows=new ArrayList<>(9);
	List<HashSet<Character>> cols=new ArrayList<>(9);
	List<HashSet<Character>> block=new ArrayList<>(9);
	
	List<Integer> blank=new ArrayList<>();
	//解数独
	public void solveSudoku(char[][] board) {
		for(int k=0;k<9;k++) {
			rows.add(new HashSet<>());
			cols.add(new HashSet<>());
			block.add(new HashSet<>());
			for(int v=1;v<=9;v++) {
				rows.get(k).add((char)(v+48));
				cols.get(k).add((char)(v+48));
				block.get(k).add((char)(v+48));
			}
		}
		//收集空格
		for(int i=0;i<9;++i) {
			for(int j=0;j<9;++j) {
				if(board[i][j]!='.') {
					rows.get(i).remove(board[i][j]);
					cols.get(j).remove(board[i][j]);
					block.get(i/3*3+j/3).remove(board[i][j]);
				}else {
					blank.add(i*9+j);
				}
			}
		}
		 _backtrack(board,0);
	}

	private boolean _backtrack(char[][] board, int iter) {
		if (iter == blank.size())
			return true;
		int i = blank.get(iter) / 9;
		int j = blank.get(iter) % 9;
		int b = (i / 3) * 3 + j / 3;
		for (int val = 1; val <= 9; val++) {
			char cur = (char) (val + 48);
			if (rows.get(i).contains(cur) && cols.get(j).contains(cur) 
					&& block.get(b).contains(cur)) {
				rows.get(i).remove(cur);
				cols.get(j).remove(cur);
				block.get(b).remove(cur);
				board[i][j] = cur;
				if (_backtrack(board,iter+1))
					return true;
				rows.get(i).add(cur);
				cols.get(j).add(cur);
				block.get(b).add(cur);
			}
		}
		return false;
	}
}
```