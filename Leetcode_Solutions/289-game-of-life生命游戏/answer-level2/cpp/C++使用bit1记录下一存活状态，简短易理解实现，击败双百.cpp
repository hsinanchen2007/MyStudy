![O4AFOIJRV))QPP~K71\[9}(T.png](https://pic.leetcode-cn.com/07c876870e3ac3ef05b27878bb7d4d0674031423736fc787cf2fa61f915106e9-O4AFOIJRV\)\)QPP~K71%5B9%7D\(T.png)
### 解题思路
使用bit 1记录细胞下一存活状态状态, 遍历一遍即可. 思路详见代码注释.
	注：因为bit1默认为0, 故遍历过程中只需关注下一状态为存活的情况
		即—— i. 活细胞周围活细胞数量为2或3  
			ii. 死细胞周围活细胞数量为3


### 代码

```cpp
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty()) return;
		for (int i = 0; i < board.size(); i++){
			for (int j = 0; j < board[0].size(); j++){
				int count = countAround(board, i, j);
				if ((count > 1 && count < 4 && board[i][j] == 1) /*活细胞存活*/\
							|| (count == 3 && board[i][j] == 0)/*死细胞复活*/)
					board[i][j] += 2; //bit 1置1
			}
		}
		 for(int i = 0; i < board.size(); i++)
		     for(int j = 0; j < board[0].size(); j++)
		         board[i][j] = board[i][j] >> 1; //更新细胞下一存活状态
	}
private:
	int countAround(vector<vector<int>>& board, int i, int j){ //计算周围存活细胞数量
		vector<int> dirs = { -1, 0, 1 };//移动方向
		int count = 0;
		for (auto diri : dirs)
			for (auto dirj : dirs)
				if ((diri != 0 || dirj != 0) /*i=j=0为当前中心*/&& judge(board, i + diri, j + dirj)/*判断在界内且存活*/)
					count++;
		return count;
	}
	bool judge(vector<vector<int>>& board, int i, int j){
		return(i >= 0 && i < board.size() && j >= 0 && j < board[0].size() && (board[i][j] & 0x01 == 1));
	}
};
```