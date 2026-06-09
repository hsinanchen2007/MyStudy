### 解题思路
参考别人的思路

### 代码

```cpp
class Solution {
public:
int move(vector< vector<char> > board, int cur_x, int cur_y, int x_d, int y_d)//递归模拟车的移动
{
    //如果越界或者碰到了象，说明没找到可以吃的卒，返回0
	if (cur_x <0 ||cur_x > board.size() - 1 || cur_y < 0 || cur_y > board.size() - 1 || board[cur_y][cur_x] == 'B')
	{
		return 0;
	}
    //如果碰到了卒，就返回1,表示吃掉了一个卒
	if (board[cur_y][cur_x] == 'p')
	{
		return 1;
	}
    //上面两种情况都不满足，那就继续移动
	cur_x = cur_x + x_d;
	cur_y = cur_y + y_d;
    //返回吃掉的卒的个数
	return move(board, cur_x, cur_y, x_d, y_d);
}
    int numRookCaptures(vector<vector<char>>& board) {
int count = 0;
	int cur_x, cur_y;//表示车在棋盘中的初始位置,cur_x表示列，cur_y表示行
    //x和y的方向数组，两个数组垂直组合就可以表示上下左右的方向（我这里是下、上、右、左）
	int x_d[] = { 0, 0, 1,-1 };
	int y_d[] = { 1, -1, 0, 0 };
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board.size(); j++)//两层for找车的位置
		{
			if (board[i][j] == 'R')
			{
                //得到了车的坐标位置
				cur_x = j;
				cur_y = i;
				for (int k = 0; k < 4; k++)//一直向某一个方向移动，如果找到了卒或者遇到了象或者越界，就换另一个方向一直走
				{
					count = count + move(board, cur_x, cur_y, x_d[k], y_d[k]);//总的可以吃的卒的个数
					
				}
				return count;
			}
		}
	}
    return 0;//如果棋盘中没有车
    }
};

```