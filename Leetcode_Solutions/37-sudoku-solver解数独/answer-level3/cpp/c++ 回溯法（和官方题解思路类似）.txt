首先用3个bool数组对一个数字的行列格情况进行存储
    row[9][10]
    column[9][10]
    lattic[9][10]//第i行/列/格是否有第j个数字
具体实现通过
void setBool(int _row, int _column, int num, bool flag) {
	row[_row][num] = column[_column][num] = lattic[latticNum(_row, _column)][num] = flag;
}
以及判断函数
bool isSetBool(int _row, int _column, int num) {
	return row[_row][num] || column[_column][num] || lattic[latticNum(_row, _column)][num];
}

然后就是回溯的基本思路
第i行第j列
    board[_row][_column]=i+'0';
    setBool(_row,_column,i,true);
    //回溯函数
    setBool(_row,_column,i,false);
    board[_row][_column]='.';

下面贴代码
    bool row[9][10], column[9][10], lattic[9][10];
    bool isSolved = false;
    //判断哪一格
    int latticNum(int _row, int _column) {
	    return 3 * (_row / 3) + _column / 3;
    }

    void setBool(int _row, int _column, int num, bool flag) {
    	row[_row][num] = column[_column][num] = lattic[latticNum(_row, _column)][num] = flag;
    }

    bool isSetBool(int _row, int _column, int num) {
	    return row[_row][num] || column[_column][num] || lattic[latticNum(_row, _column)][num];
    }
    //回溯函数
    void perm(vector<vector<char>>& board, int _row, int _column) {
	    if (_row == 9) {
	    	isSolved = true;
	    	return;
    	}
	    if (board[_row][_column] != '.') {
            //回溯到行尾的判断
	    	if (_column < 8)
	    		perm(board, _row, _column + 1);
	       	else
	    		perm(board, _row + 1, 0);
	    	return;
    	}
    	else {
    		for (int i = 1; i < 10; ++i) {
	    		if (isSetBool(_row, _column, i))
	    			continue;
	    		board[_row][_column] = i + '0';
	    		show(board);
	    		setBool(_row, _column, i, true);
		    	if (_column < 8)
		    		perm(board, _row, _column + 1);
		    	else
		    		perm(board, _row + 1, 0);
		    	if(isSolved)
		    		return;
		    	board[_row][_column] = '.';
		    	setBool(_row, _column, i, false);
		    }
	    }
    }

    void solveSudoku(vector<vector<char>>& board) {
	    for (int i = 0; i < 9; ++i) {
	    	for (int j = 0; j < 9; ++j) {
		    	if ('.' == board[i][j])
		    		continue;
		    	int num = board[i][j] - '0';
		    	setBool(i, j, num, true);
	    	}
        }
	    perm(board, 0, 0);
    }
