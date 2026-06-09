```
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> map(8, vector<int>(8, 0));
		//初始化皇后位置
		for (auto t : queens)
		{
			map[t.at(0)][t.at(1)] = 1;
		}
		//初始化国王位置
		map[king.at(0)][king.at(1)] = 2;

		int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
		int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
		vector<vector<int>> ansArr = vector<vector<int>>{};
		for (size_t i = 0; i < 8; i++)
		{
			int x = king.at(0);
			int y = king.at(1);

			do 
			{
				x += dx[i];
				y += dy[i];
				//判断越界
				if (x < 0 || x >= 8 || y < 0 || y >= 8) break;;

				//判断是否遇到皇后
				if (map[x][y] == 1)
				{
					ansArr.push_back(vector<int>{x, y});
					break;
				}
			} while (true);
		}

		return ansArr;
    }
};
```
以国王为起点，向八个方向查找皇后，找到第一个就跳出，查找下一个。