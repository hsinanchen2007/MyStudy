### 解题思路
通过建立一个棋盘来模拟实现n皇后的布置操作。每一个n皇后放上之后都会导致棋盘中一部分区域变为“非法区域“。
刚开始的时候我想的是通过一个bool变量的棋盘来实现对非法、合法区域的区分。后面发现有些区域是由多个皇后重叠造成的非法区域。
因此后面我将checkboard改为了int类型的。通过它的数值大小来判断该区域是由几个皇后叠加形成的非法区域。当数值为0的时候，表示该位置可以放置皇后。
其中我认为几个容易出错的地方是：
1、回溯的时候没有将皇后取出，也就是没有把该皇后形成的非法区域变回合法区域。
2、设计bool量来分别表示是否需要回溯和最终终止循环。
3、放置皇后之后对棋盘上的数值的变化，（按我的方法变化的话，注意后面要减去3倍的increment，因为在皇后放置位置处一共加了四次）

### 代码

```cpp
#define setQueen true
#define removeQueen false
class Solution {
public:
	vector<vector<string>> solveNQueens(int n);
private:
	void clear();
	int queenNum;// the number of queens
	void initialize(int n);//initialize  class members
	vector<vector<int>>checkBoard;//checkBoard
	bool putQueen(int setN, int position);// determine whether to put queen on the checkboard;
	void setPosition(int setN, int position, bool setFlag = false);// adjust checkboard layout
	void print();
	void testMode(int x, int y);
};
void Solution::clear() {
	checkBoard.clear();
}
void Solution::initialize(int n) {
	queenNum = n;
	vector<int> temp(n, 0);
	for (int i = 0; i < n; i++)
		checkBoard.push_back(temp);
}
bool Solution::putQueen(int setN, int position) {
	if (checkBoard[setN][position] == 0) {
		setPosition(setN, position, setQueen);
		return true;
	} 
	return false;
}
void Solution::setPosition(int setN, int position, bool setFlag) {
	int increment;
	if (setFlag == setQueen)
		increment = 1;
	else
		increment = -1;
	for (int i = 0; i < queenNum; i++) {
		checkBoard[i][position] += increment;//change value in the  vertical direction
		checkBoard[setN][i] += increment;
	}

	int x = position;
	int y = setN;
	while (x > 0 && y > 0) {
		x--;
		y--;
	}//move the cursor to the southwest of checkboard
	while (x < queenNum && y < queenNum) {
		checkBoard[y][x] += increment;
		x++;
		y++;
	}//move the cursor to the northeast  and change the value in the way
	x = position;
	y = setN;
	while (x > 0 && y < queenNum - 1) {
		x--;
		y++;
	}//move the cursor to the northwest  of the checkboard and change the value in the way
	while (x < queenNum && y >= 0) {
		checkBoard[y][x] += increment;
		x++;
		y--;
	}// move the cursor to the southeast 
	checkBoard[setN][position] -= increment * 3;
}
void Solution::print() {
	for (int i = 0; i < queenNum; i++){
		for (int j = 0; j < queenNum; j++)
			cout << checkBoard[i][j];
		cout << endl;
	}
	cout << endl << endl << endl;
}
void Solution::testMode(int x, int y) {
	setPosition(x, y);
	print();
	setPosition(x, y, true);
	print();
}
vector<vector<string>> Solution::solveNQueens(int n) {
	clear();
	initialize(n);
	vector<int> queens(n, 0);
	vector<vector<string>> result;
	int setN = 0;
	bool recallFlag = false;
	bool successfulFlag = false;
	bool overFlag = false;
#ifdef DEBUG1
	testMode(1, 1 );
#endif
	while (!overFlag) {
		for (int i = 0; i < n; i++) {
			if (putQueen(setN, i)) {
#ifdef DEBUG
				print();
#endif
				queens[setN] = i;
				if (setN == n - 1) {
					string temp(n, '.');
					vector<string> temp_result;
					for (int i = 0; i < n; i++) {// save the result
						temp[queens[i]] = 'Q';
						temp_result.push_back(temp);
						temp[queens[i]] = '.';
					}
					recallFlag = true;
					result.push_back(temp_result);
					setPosition(setN, queens[setN], removeQueen);// keep looking for result
#ifdef DEBUG
					print();
#endif
					break;
				}
				setN++;
				break;
			}
			if (i == n - 1)
				recallFlag = true;
;		}
		while (recallFlag) {// recall and find the suitable position
			setN--;
			if (setN < 0) {// back in the end
				overFlag = true;
				break;
			}

			setPosition(setN, queens[setN], removeQueen);//remove the queen and reset checkboard
#ifdef DEBUG
			print();
#endif
			for (int i = queens[setN] + 1; i < n; i++) {
				if (putQueen(setN, i)) {
#ifdef DEBUG
					print();
#endif
					queens[setN] = i;
					setN++;
					recallFlag = false;
					break;
				}
			}
		}
	}
	return result;
}
```