
```
class Solution {
public:
    //Runtime: 4 ms, faster than 59.70% of C++ online submissions for Find Winner on a Tic Tac Toe Game.
    //Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Find Winner on a Tic Tac Toe Game.
	string tictactoe(vector<vector<int>>& moves) 
	{
		vector<vector<int>> map(3, vector<int>(3, 0));
		bool bIsFirst = true;
		for (size_t i = 0; i < moves.size(); i++)
		{
			int x = moves[i][0];
			int y = moves[i][1];
			int target = bIsFirst ? 1 : 2;
			map[x][y] = target;
			if (i > 3 && 
				(IsWin(map, x, y, 1, 1, target)
					|| IsWin(map, x, y, -1, 1, target)
					|| IsWin(map, x, y, 0, 1, target)
					|| IsWin(map, x, y, 1, 0, target)))
			{
				return bIsFirst ? "B" : "A";
			}

			bIsFirst = !bIsFirst;
		}
		return moves.size() > 8 ? "Draw" : "Pending";
	}

	bool IsWin(vector<vector<int>> map, int x, int y, int x_dir, int y_dir, int target)
	{
		int x_offset = x_dir, y_offset = y_dir, res = 1;
		while (x + x_offset >= 0 && y + y_offset >= 0 && x + x_offset < map.size() && y + y_offset < map.size())
		{
			if (map[x + x_offset][y + y_offset] == target)
			{
				++res;
				x_offset += x_dir;
				y_offset += y_dir;
			}
			else
			{
				break;
			}
		}
		x_offset = -x_dir;
		y_offset = -y_dir;
		while (x + x_offset >= 0 && y + y_offset >= 0 && x + x_offset < map.size() && y + y_offset < map.size())
		{
			if (map[x + x_offset][y + y_offset] == target)
			{
				++res;
				x_offset -= x_dir;
				y_offset -= y_dir;
			}
			else
			{
				break;
			}
		}
		return res > 2;
	}
};
```
