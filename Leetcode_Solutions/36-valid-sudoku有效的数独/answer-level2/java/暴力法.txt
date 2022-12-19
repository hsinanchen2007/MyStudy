public boolean isValidSudoku(char[][] board) {
		 boolean isR=true;
		 boolean isC=true;
		 boolean is9=true;
        //验证所有行
		 for(int i=0;i<9;i++) {
			 isR=isR&&validateRow(i,board);
		 }
		 //验证所有列
		 for(int i=0;i<9;i++) {
			 isC=isC&&validateCol(i,board);
		 }
		 //验证9宫格
		for (int i = 0; i < 7; i=i+3)
			for (int j = 0; j < 7; j=j+3) {
				isC = isC && validate9(i, j, board);
			}
		return isC&&isR&&is9;
	}
	 //验证行
	 public boolean validateRow(int num,char[][] board) {
		 char[] val = new char[] {'T','T','T','T','T','T','T','T','T','T'};
		 for(int i=0;i<9;i++) {
			 if(board[num][i]=='.')continue;
			 char temp=val[board[num][i]-'0'];
			 if(temp=='F')
				 //if(val[Integer.parseInt(board[num][i]+'')]=='F')
				 return false;
			 else {
				 val[board[num][i]-'0']='F';
			 }
		 }
		 return true;
	 }
	 //验证列
	 public boolean validateCol(int num,char[][] board) {
		 char[] val = new char[] {'T','T','T','T','T','T','T','T','T','T'};
		 for(int i=0;i<9;i++) {
			 if(board[i][num]=='.')continue;
			 char temp=val[board[i][num]-'0'];
			 if(temp=='F')
				 return false;
			 else {
				 val[board[i][num]-'0']='F';
			 }
		 }
		 return true;
	 }
	 //验证9宫格,begin开始的行，end开始的列
	 public boolean validate9(int begin,int end,char[][] board) {
		 char[] val = new char[] {'T','T','T','T','T','T','T','T','T','T'};
		 for(int i=begin;i<begin+3;i++)
			 for(int j=end;j<end+3;j++) {
				 if(board[i][j]=='.')continue;
				 char temp=val[board[i][j]-'0'];
				 
				 if(temp=='F')
					 return false;
				 else {
					 val[board[i][j]-'0']='F';
				 }
			 }
		 
		 
		 return true;
	 }
	 