    //人工智能经典算法，N皇后问题
	
	List<List<String>> res = new java.util.LinkedList<>();
	boolean[] col, dia1, dia2;
	public List<List<String>> solveNQueens(int n) {
		 if(n < 1) return res;
		 LinkedList<Integer> list = new LinkedList<>();
		 col = new boolean[n];
		 dia1 = new boolean[2 * n - 1];
		 dia2 = new boolean[2 * n - 1];
		 putQueens(n,0,list);
		 return res;
	}
	private void putQueens(int n, int index, LinkedList<Integer> list) {
		// 放置N皇后，参数  N行N列矩阵，在第index行放置N皇后，list用于记录
		if(index == n) {
			res.add(generateBoard(n, list));	//构造一个函数，使得输出符合要求格式
			//res.add((List<String>) list.clone());  这里不能直接这么强转，会导致输出不符合要求
		}
		for(int i = 0; i < n; i ++) {
			if(!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
				list.add(i);
				col[i] = true;
				dia1[index + i] = true;
				dia2[index - i + n - 1] = true;
				putQueens(n, index + 1, list);	//继续递归，寻找下一行如何摆放N皇后
				col[i] = false;
				dia1[index + i] = false;
				dia2[index - i + n - 1] = false;
				list.remove(list.size() - 1);
			}
		}	
	}
	
	private List<String> generateBoard(int n, LinkedList<Integer> list) {
		// 将点记录成String矩阵
		assert list.size() == n;
		List<String> board = new LinkedList<>();
		for(int i = 0; i < n; i ++) {
			char[] charA = new char[n];
			Arrays.fill(charA, '.');
			charA[list.get(i)] = 'Q';
			board.add(new String(charA));
		}
		return board;
	}