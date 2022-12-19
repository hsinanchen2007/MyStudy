

    public List<List<String>>  solveNQueens(int n) {
		List<List<String>> result=new ArrayList<List<String>>();
		//给棋盘赋初值
        char[][] box =new char[n][n];
        for(int i=0;i<n;i++)
        	for(int j=0;j<n;j++)
        		box[i][j]='.';
        backtrace(box,0,0,n,result);	
		return result;
    }
	//回溯法求解
	private void backtrace(char[][] box, int row,int begin,int n,List<List<String>> result) {
		if(row==n) {
			List<String> temp=new ArrayList<String>();
			for(int i=0;i<n;i++) {
				String str="";
				for(int j=0;j<n;j++) {
					str=str+String.valueOf(box[i][j]);
				}
				temp.add(str);
			}
			result.add(new ArrayList<String>(temp));
			return;
		}
		for(int i=0;i<n;i++) {
			box[row][i]='Q';
			if(check0(box,row,i)&&check1(box,row,i)&&check2(box,row,i,n)) {
				backtrace(box,row+1,i+1,n,result);
			}
			box[row][i]='.';
		}
		
	}
	//检查列有无皇后
	private Boolean check0(char[][] box,int row,int col) {
		for(int i=0;i<row;i++) {
			if(box[i][col]=='Q')return false;
		}
		return true;
	}
	
	//检查对角线有无皇后
	private Boolean check1(char[][] box,int row,int col) {
		for(int i=row-1 ,j=col-1;i>=0&&j>=0;i--,j--) {
			if(box[i][j]=='Q')
				return false;
			}
		
		return true;
	}
	//检查对角线有无皇后
	private Boolean check2(char[][] box,int row,int col,int n) {
		for(int i=row-1 ,j=col+1;i>=0&&j<n;i--,j++) {
			if(box[i][j]=='Q')
				return false;
			}
		
		return true;
	}
	
