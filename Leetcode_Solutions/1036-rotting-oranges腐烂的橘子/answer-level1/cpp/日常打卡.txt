### 解题思路

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    int sum_all = 0;	//记录橘子的总数
	int sum_old = 0;	//记录坏橘子的数量
	int time = 0;		//用的时间
	int new_size = 0;	
	if (grid.size() < grid[0].size())
		new_size = grid[0].size();
	else
		new_size = grid.size();
	new_size = new_size + 2;
	vector<vector<int>> new_grid(new_size);
	for (int i = 0; i < new_size; i++)
		for (int j = 0; j < new_size; j++) {
			new_grid[i].push_back(0);
		}
	for (int i = 1; i < grid.size() + 1; i++)
		for (int j = 1; j < grid[0].size() + 1; j++) {
			new_grid[i][j] = grid[i - 1][j - 1];
		}
	//一直到这里都是将原来的二维数组扩大一圈，用零包围住，防止数组读取错误。
	for (int i = 1; i < grid.size() + 1; i++)
		for (int j = 1; j < grid[0].size() + 1; j++) {
			if (new_grid[i][j] != 0) {
				sum_all++;
				if (new_grid[i][j] == 2)
					sum_old++;	
			}
		}//获取橘子总数和开始前坏橘子的数量
		int end = 1;//结束标志
		while (end == 1) {
			end = 0;//设置结束标志，若未重置则循环停止，重置条件是有橘子被感染，无橘子被感染时表示循环结束。
			for (int i = 1; i < grid.size() + 1; i++)
				for (int j = 1; j < grid[0].size() + 1; j++) {
					if (new_grid[i][j] == 2+time) {//查找第n轮开始感染的橘子
						for (int k = 0; k < 4; k++) {//四个方向检查是否可以感染，如果可以感染，则将其感染后放到下一轮，将感染橘子总数加一，重置结束标志，继续循环。
							if (new_grid[i][j + 1] == 1) {
								new_grid[i][j + 1] = 3 + time;
								sum_old++;
								end = 1;
							}
							else if (new_grid[i][j - 1] == 1) {
								new_grid[i][j - 1] = 3 + time;
								sum_old++;
								end = 1;
							}
							else if (new_grid[i + 1][j] == 1) {
								new_grid[i + 1][j] = 3 + time;
								sum_old++;
								end = 1;
							}
							else if (new_grid[i - 1][j] == 1) {
								new_grid[i - 1][j] = 3 + time;
								sum_old++;
								end = 1;
							}
						}
					}
				}
			if(end == 1)//只有当结束标志为一时，时间才会增加，结束标志为零时，表示感染结束，时间不再增加。
			time++;
		}
		if (sum_all != sum_old)//若全部结束后，感染橘子数与橘子总数不相同，即有橘子未被感染，则时间为-1.
			time = -1;
        return time; //返回时间
    }
};
```