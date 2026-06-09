利用回溯法解数独；
将每一个空格进行试数，从0-9，如果能存在就进行下一个空格的试数，如果当前空格已经试数到了9还不能存在就进行回溯
```
char board2[9][9];//board的代替数组
//ifset用来判断关键书key能否在当前空格中存在
int ifset(char** board,int key, int start, int rows[], int cols[]){
    int i_start = rows[start];
    int j_start = cols[start];
    int i, j;
   for(j = 0; j<9; j++){//检查所在的行和列是否有重复的数；
        if(board[i_start][j] - '0' == key || board[j][j_start] - '0' == key)
            return 0;
    }
    for(i = i_start - i_start%3; i< i_start - i_start%3 + 3; i++){//检查所在的九宫格是否有重复的数
        for(j = j_start -j_start%3; j<j_start -j_start%3 + 3; j++){
            if(board[i][j] - '0' == key)
                return 0;
        }
    }
    return 1;
}

void setSudoku(char** board, int start, int need_w_nums, int rows[], int cols[]){
   //如果当前空格已经全部填完，用board2来复制board，，，ps：因为本人实在是不知道如何在全部回溯完之后
  //还能正常输出已经填完的board，所以只能用一个board2来代替。如有大佬看出错误还请帮忙指教。
 if(start == need_w_nums)     
{
    	for(int i = 0; i<9; i++)
    	{
    		for(int j =0 ; j<9; j++){
    			board2[i][j] = board[i][j];
			}
		}
    	
        return;
	}
    int k = 1;
    for(k = 1; k<=9;k++){
    	if(ifset(board, k,start,rows,cols)){
            board[rows[start]][cols[start]] = '0' + k;
            setSudoku(board,start+1,need_w_nums,rows,cols);
           //此语句用来判断是否为回溯的点，并把之前无效点改为 ' . '
 if(start+1!=need_w_nums && board[rows[start+1]][cols[start+1]] != '.') 
                board[rows[start+1]][cols[start+1]] = '.';
        }
	}
}

void solveSudoku(char** board, int boardSize, int* boardColSize){
//由于实在是不知道boardSize和boardColSize具体是干嘛用的，所以系统给的这个函数我就当是个摆设
    int i, j;
    int need_w_nums = 0;//需要填充数据的个数
    int rows[81];//需要填充数据的所在行
    int cols[81];//需要填充数据的所在列
    for(i = 0; i<9; i++){
        for(j = 0; j<9; j++){
            if(board[i][j]=='.'){
                rows[need_w_nums] = i;
                cols[need_w_nums] = j;
                need_w_nums++;
            }
        }
    }
    setSudoku(board,0,need_w_nums,rows,cols);
    for(i = 0; i<9; i++)
    for(j = 0; j<9; j++)
    board[i][j] = board2[i][j];
}
```

因为我看评论和解题中的例子没有c的，所以自己写了一个，希望会c的大佬能帮忙指正其中的错误，谢啦!!☆⌒(*＾-゜)v