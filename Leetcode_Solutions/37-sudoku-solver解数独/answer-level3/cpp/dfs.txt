```
class Solution {
public:
    bool initial(vector<vector<char>>& board){
        memset(row,0,sizeof(row));
        memset(colum,0,sizeof(colum));
        memset(block,0,sizeof(block));
        
        for(int i = 0;i < board.size(); ++i){
            for(int j = 0;j < board[0].size(); ++j){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0';
                    int b = i/3*3 + j/3;
                    row[i][num] = 1;
                    colum[j][num] = 1;
                    block[b][num] = 1;
                }else{
                    blank.push_back(make_pair(i,j));
                }
            }
        }
        
        return true;
    }
    
    
	void solveSudoku(vector<vector<char>>& board) {        
        /*initial*/
		initial(board);
        helper(board,0);
	}

	bool helper(vector<vector<char>>& board,const int pos) {
        if(pos >= blank.size()){
            return true;
        }
        
		int x = blank[pos].first;
        int y = blank[pos].second;
        int z = x/3*3 + y/3;
            
        for(int i = 1; i <= 9; ++i){
            if(!row[x][i]&&!colum[y][i]&&!block[z][i]){
                board[x][y] = i + '0';
                  row[x][i] = 1;
                colum[y][i] = 1;
                block[z][i] = 1;
                
                if(helper(board,pos+1)){
                    return true;
                }else{
                    board[x][y] = '.';
                      row[x][i] = 0;
                    colum[y][i] = 0;
                    block[z][i] = 0;
                }
            }
        }
        
        return false;
	}

private:
	int row[9][10];
    int colum[9][10];
    int block[9][10];
    vector<pair<int,int>> blank;
};

```