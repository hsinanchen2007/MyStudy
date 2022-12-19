主要有两个技巧：
1.int占32位，可以用多余的位存储中间数据。
2.怎么计算周围活细胞的和。
用一个int的不同位存储多种状态有很多人都说过了，不再赘述。主要想说一下怎么去计算周围细胞的和，除了直接把周围八个格子相加，还有一种方法节约计算量。
首先我们遍历一边数组，把每一个细胞自身、左边、右边相加，结果保存到int的第5-8位。
第二步，再遍历一遍数组，这一次在上一步的基础上，再分别加上上边和下边的细胞。这一步巧妙的地方在于：有了上一步的中间数据，我们通过一次加法就可以同时加上左上、上、右上（或者左下、下、右下）三个细胞的状态，原有的8次加法可以简化为4次加法和1次减法。
第三步，把自身减掉（只考虑周围的细胞状态）。
第四步，最后一次遍历，根据自身和周围细胞状态更新。（这一步也可以直接在2、3步遍历时做，为了稍微清晰一点，这里单独分出来）

代码是真的辣鸡，只展示思路，污染了大家的眼睛，对不起。（多套了些括号，可能看起来会清楚一点点了，求放过）

![QQ图片20200402233115.png](https://pic.leetcode-cn.com/e1cc42fb80faa7e31f860750a56c854596744a351d4e4d1990c165b07ea05def-QQ%E5%9B%BE%E7%89%8720200402233115.png)


```
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				board[i][j] = ((((j == 0 ? 0 : board[i][j - 1]) + board[i][j] + (j == board[i].size() - 1 ? 0 : board[i][j + 1])) & 0xF) << 4) + board[i][j];
			}
		}
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				board[i][j] += (((i == 0 ? 0 : (board[i - 1][j] & 0xF0)) - ((board[i][j] & 0xF) << 4) + (board[i][j] & 0xF0) + (i == board.size() - 1 ? 0 : (board[i + 1][j] & 0xF0))) & 0xF0) << 4;
			}
		}
		for (int i = 0; i < board.size(); ++i)
		{
			for (int j = 0; j < board[i].size(); ++j)
			{
				if (((board[i][j] >> 8) < 2) || ((board[i][j] >> 8) > 3))
					board[i][j] = 0;
				else if ((board[i][j] >> 8) == 3)
					board[i][j] = 1;
				else
					board[i][j] &= 0xF;
			}
		}
	}
};
```
