基本思路：从board中逐个提取元素和word中首个元素比较，相同时开始深度搜索，从该元素上下左右（保证在范围内）的元素进行比较，发现相同则递归地比较下去，如果都不相同说明以该点为首个元素找不到该单词

整道题的思路比较简单，关键在于对于数据量较大的变量最好采用引用传递而不是值传递

代码如下：


```
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution 
{
	private:
		struct offset
		{
			short int vert;
			short int Horiz;
		};
		struct offset Move[4];
	public:
		Solution()    // 构造函数
		{
			Move[0] = {  0, 1 };    // 上
			Move[1] = {  0,-1 };    // 下
			Move[2] = { -1, 0 };    // 左
			Move[3] = {  1, 0 };    // 右
		}
		bool recursive(vector<vector<char>>& board, vector<vector<bool>> &Mark, int row, int col, string word) // 引用比值传递效率更高
		{
			int cur_row, cur_col;
			int real_row = row, real_col = col;
			int row_size = board.size(), col_size = board[0].size();

			if (word.size() == 0)
			{
				return true;
			}
			else
			{
				for (int dir = 0; dir < 4; dir++)
				{
					cur_row = row + Move[dir].Horiz;
					cur_col = col + Move[dir].vert;
					if (cur_row < row_size && cur_row >= 0 && cur_col < col_size && cur_col >= 0  )
					{
						if (Mark[cur_row][cur_col] == false && board[cur_row][cur_col] == word[0])
						{
							Mark[cur_row][cur_col] = true;
							if (recursive(board, Mark, cur_row, cur_col, word.substr(1, word.size() - 1)))    // 递归搜索
							{
								return true;
							}
							else
							{
								Mark[cur_row][cur_col] = false;
							}
						}
					}
				}
				return false;    // 四个方向都找不到
			}

		}
		bool exist(vector<vector<char>>& board, const string word) 
		{
			vector<vector<bool>> Mark(board.size(), vector<bool>(board[0].size(), false));
			for (int i = 0; i < board.size(); i++)
			{
				for (int j = 0; j < board[0].size(); j++)
				{
					if (board[i][j] == word[0])
					{
						Mark[i][j] = true;
						if (recursive(board, Mark, i, j, word.substr(1, word.size() - 1)))
						{
							return true;
						}
						else
						{
							Mark[i][j] = false;
						}
					}
				}
			}
			return false;

		}
};
```


其中成员函数 bool recursive(vector<vector<char>>& board, vector<vector<bool>> Mark, int row, int col, string word) 的Mark变量采用值传递时，运行结果
![image.png](https://pic.leetcode-cn.com/a671988ab0c15fb5d0e0366cb1c8224121e3826d483a3d1d9e16f751750ee8c6-image.png)

改用引用传值 bool recursive(vector<vector<char>>& board, vector<vector<bool>> &Mark, int row, int col, string word)
![image.png](https://pic.leetcode-cn.com/a914f51831204f10bf87e5f6352cc50d19b299fb7f5979136f421fc97f1533db-image.png)

可见不同的传值方式对程序结果影响还是比较大的

欢迎关注我的github：https://github.com/hit-lu/Algorithm，里面有持续更新的题目解答方式

也欢迎邮箱交流：hit_lu@foxmail.com
