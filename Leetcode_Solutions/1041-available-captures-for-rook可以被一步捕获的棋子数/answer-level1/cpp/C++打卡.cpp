### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
	size_t width = 8;
	bool getRookIJ(vector<vector<char>>& board, int& rookI, int& rookJ) {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < width; j++) {
				if (board.at(i).at(j) == 'R') {
					rookI = i;
					rookJ = j;
					return true;
				}
			}
		}
		return false;
	}
public:
	int numRookCaptures(vector<vector<char>>& board) {
		int rookI = 0, rookJ = 0, ans = 0;
		if (getRookIJ(board, rookI, rookJ) == false) {
			return 0;
		}
		//向上
		for (int i = rookI; i >= 0;i--) {
			if (board.at(i).at(rookJ) == '.') {
				//空格，则查找下一格
			}
			else if (board.at(i).at(rookJ) == 'B') {
				//白色的象（bishop），则无法移动到下一格
				break;
			}
			else if (board.at(i).at(rookJ) == 'p') {
				//黑色的卒（pawn）,则说明可以捕获到卒
				ans++;
				break;
			}
		}
		//向下
		for (int i = rookI; i < width; i++) {
			if (board.at(i).at(rookJ) == '.') {
				//空格，则查找下一格
			}
			else if (board.at(i).at(rookJ) == 'B') {
				//白色的象（bishop），则无法移动到下一格
				break;
			}
			else if (board.at(i).at(rookJ) == 'p') {
				//黑色的卒（pawn）,则说明可以捕获到卒
				ans++;
				break;
			}
		}
		//向左
		for (int j = rookJ; j >= 0; j--) {
			if (board.at(rookI).at(j) == '.') {
				//空格，则查找下一格
			}
			else if (board.at(rookI).at(j) == 'B') {
				//白色的象（bishop），则无法移动到下一格
				break;
			}
			else if (board.at(rookI).at(j) == 'p') {
				//黑色的卒（pawn）,则说明可以捕获到卒
				ans++;
				break;
			}
		}
		//向右
		for (int j = rookJ; j < width; j++) {
			if (board.at(rookI).at(j) == '.') {
				//空格，则查找下一格
			}
			else if (board.at(rookI).at(j) == 'B') {
				//白色的象（bishop），则无法移动到下一格
				break;
			}
			else if (board.at(rookI).at(j) == 'p') {
				//黑色的卒（pawn）,则说明可以捕获到卒
				ans++;
				break;
			}
		}
		return ans;	
	}
};
```