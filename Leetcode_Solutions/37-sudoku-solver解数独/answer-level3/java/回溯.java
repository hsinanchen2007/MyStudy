	
	char[] material = {'1','2','3','4','5','6','7','8','9'};
	char empty = '.';
	int length = 9;
	boolean success = false;

    public void solveSudoku(char[][] board) {
    	
    	HashSet<Character>[] rows = new HashSet[length];
    	HashSet<Character>[] cols = new HashSet[length];
    	HashSet<Character>[] boxs = new HashSet[length];
    	for(int i=0; i<length; i++){
    		rows[i] = new HashSet<>();
    		cols[i] = new HashSet<>();
    		boxs[i] = new HashSet<>();
    	}
    	// 保存已填充的内容
    	for(int row=0; row < length; row ++){
    		for(int col=0; col<length;  col++){
    			if(board[row][col] != empty){
    				rows[row].add(board[row][col]);
    				cols[col].add(board[row][col]);
    				boxs[3*(row/3) + col/3].add(board[row][col]);
    			}
    		}
    	}
    	
    	// 从 第一个格子开始填充
    	int row = 0, col = 0;
    	putBlank(row, col, rows, cols, boxs, board);
    	
    }
	
	private void putBlank(int row, int col, HashSet<Character>[] rows, HashSet<Character>[] cols,
			HashSet<Character>[] boxs, char[][] board) {
		if(row == length ){
	    	for(int i=0; i < length; i ++){
	    		System.out.println();
	    		for(int j=0; j<length;  j++){
		    		System.out.print(new StringBuilder().append(board[i][j]).append(" ").toString());
	    		}
	    	}
	    	success = true;
			return;
		}
		if(success){
			return;
		}
		// 计算后面的行和列
		int nextRow = 0, nextCol = 0;
		if(col == length-1){
			nextCol = 0;
			nextRow = row + 1;
		}else{
			nextCol = col + 1;
			nextRow = row;	
		}
		
		if(board[row][col] != empty){
			// 已经有值的直接的跳过
			putBlank(nextRow, nextCol, rows, cols, boxs, board);
		}else{
			// 遍历所有的可能性
			for(int i=0; i<material.length; i++){
				if(!boxs[3*(row/3) + col/3].contains(material[i]) 
						&& !rows[row].contains(material[i])
						&& !cols[col].contains(material[i])
						&& !success){
					board[row][col] = material[i];
    				rows[row].add(material[i]);
    				cols[col].add(material[i]);
    				boxs[3*(row/3) + col/3].add(material[i]);
    				putBlank(nextRow, nextCol, rows, cols, boxs, board);
    				// 这里只有增加的success判断才能保留答案
    				if(!success){
    					// 这里移除已有的结果，进行回溯，防止影响后面的结果判断
        				rows[row].remove(material[i]);
        				cols[col].remove(material[i]);
        				boxs[3*(row/3) + col/3].remove(material[i]);
    					board[row][col] = empty;    					
    				}
				}
			}			
		}	
	}