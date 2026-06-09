# 51. N皇后
```
#define MAP_QUEEN 2
#define MAP_EMPTY 1
#define MAP_UNDO -1

class Solution {
private:
	vector<vector<string>> rst;
public:
	bool InsertQueen(vector<vector<int>> &map,int _row,int _col){
		int row = _row;
		int col = _col;
		if(map[row][col] != MAP_EMPTY){
			return false;
		}
		
		int mapSize = map.size();
		for(int i = 0; i < mapSize; ++i){
			map[i][col] = MAP_UNDO;
			map[row][i] = MAP_UNDO;
		}
		
		int t_row = row;
		int t_col = col;
		while((--t_row >= 0) && (--t_col >= 0)){
			map[t_row][t_col] = MAP_UNDO;
		}
		t_row = row;
		t_col = col;
		while((++t_row < mapSize) && (++t_col < mapSize)){
			map[t_row][t_col] = MAP_UNDO;
		}
		t_row = row;
		t_col = col;
		while((--t_row >= 0) && (++t_col < mapSize)){
			map[t_row][t_col] = MAP_UNDO;
		}
		t_row = row;
		t_col = col;
		while((++t_row < mapSize) && (--t_col >= 0)){
			map[t_row][t_col] = MAP_UNDO;
		}
		
		map[row][col] = MAP_QUEEN;
		
		return true;
	}
	
	void Save2Rst(vector<vector<int>> &map){
		vector<string> rst_item;
		for(auto row : map){
			string rowstr;
			for(auto data : row){
				if(data == MAP_QUEEN){
					rowstr += "Q";
				}else{
					rowstr += ".";
				}
			}
			rst_item.push_back(rowstr);
		}
		rst.push_back(rst_item);
	}
	
	void recursion(int row,vector<vector<int>> &map){
		if(row == map.size()){
			Save2Rst(map);
			return;
		}
		for(int i = 0; i < map[row].size(); ++i){
			vector<vector<int>> t_map = map;
			if(map[row][i] == MAP_EMPTY){
				InsertQueen(t_map,row,i);
				recursion(row+1,t_map);
			}
		}
	}
	
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> map(n,vector<int>(n,MAP_EMPTY));
		recursion(0,map);
		return rst;
    }
};
```
