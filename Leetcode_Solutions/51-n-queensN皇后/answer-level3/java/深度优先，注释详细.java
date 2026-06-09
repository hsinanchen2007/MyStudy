    public static List<List<String>> solveNQueens(int n) {
		List<List<String>> res = new ArrayList<>();
        if(n < 1) return res;
        int[] queen = new int[n];
        process(0, queen, n, res);
        return res;
    }
	//递归：逐行遍历棋盘。   queen数组：下标为行号，值为该皇后所在列的号
	private static void process(int row, int[] queen, int n, List<List<String>> res) {
		if(row == n) {//棋盘行数 0---n-1，row==n说明整个棋盘遍历完了 
			List<String> subResult = new ArrayList<>(n);//代表一种正确解
			for(int i = 0;i < n;i++) {//皇后的位置就在queen数组中，现在要根据queen数组还原放置皇后的棋盘图案
                StringBuilder s = new StringBuilder();
                for(int j = 0;j < n;j++) {
                	if(j == queen[i]) {//如果遍历到该行皇后所在的列
                		s.append('Q');
                	}else {
                		s.append('.');
                	}
                }
                subResult.add(s.toString());//将该行的棋子图案加入
			}
			res.add(subResult);
			return ;
		}
		for(int col = 0; col < n;col++) {//遍历这一行的所有列
			if(isValid(queen, row, col)) {
				queen[row] = col;//这个位置可以放皇后，更新queen数组
				process(row + 1, queen, n, res);
			}
		}
	}

	private static boolean isValid(int[] queen, int row, int col) {
		for(int k = 0;k < row;k++) {//遍历row之前的每一行的皇后
			//如果(row, col) 处于某个皇后的攻击范围
			if(col == queen[k] || Math.abs(k - row) == Math.abs(queen[k] - col)) return false; 
		}
		return true;
	}