`内联代码``class Solution {
private:
	map<int, int> allMap;
	bool isCorrectMap(vector<int> curBoard){
		vector<int> rightBoard = { 1, 2, 3, 4, 5, 0 };//正确的谜板
		for (int i = 0; i<6; i++){
			if (curBoard[i] != rightBoard[i]){
				return false;
			}
		}
		return true;
	}
	int vecToMapKey(vector<int> curBoard){
		int nRet = 0;
		for (int i = 0; i<6; i++){
			nRet = curBoard[i] + nRet * 10;
		}
		return nRet;
	}
	int findBoard(int step, queue<vector<int>>& nextSearchQue, vector<int> &moveCnt, vector<vector<int>> &moveMap) {
		int curSize = nextSearchQue.size();
		if (curSize == 0){
			return -1;
		}
		//根据movemap广度遍历
		for (int i = 0; i < curSize; i++){
			vector<int> nextBoardSt = nextSearchQue.front();
			nextSearchQue.pop();
			map<int, int>::iterator iter;
			int calcKey = vecToMapKey(nextBoardSt);
			iter = allMap.find(calcKey);
			if (iter == allMap.end()){//第一次经过
				allMap.insert(pair<int, int>(calcKey, step));
				if (isCorrectMap(nextBoardSt)){
					//找到了
					return step;
				}
				else{
					//找出下一层要遍历的地图
					int beginPos = 0;
					for (int m = 0; m<nextBoardSt.size(); m++){
						if (nextBoardSt[m] == 0){
							beginPos = m;
							break;
						}
					}
					for (int n = 0; n < moveCnt[beginPos]; n++){
						vector<int> tBoardSt;
						for (int j = 0; j < nextBoardSt.size(); j++){
							tBoardSt.push_back(nextBoardSt[j]);
						}
						int nTemp = nextBoardSt[beginPos];
						tBoardSt[beginPos] = nextBoardSt[moveMap[beginPos][n]];
						tBoardSt[moveMap[beginPos][n]] = nTemp;
						calcKey = vecToMapKey(tBoardSt);
						iter = allMap.find(calcKey);
						if (iter == allMap.end()){//第一次经过
							nextSearchQue.push(tBoardSt);
						}
					}
				}
			}
		}

		return findBoard(step + 1, nextSearchQue, moveCnt, moveMap);
	}
public:

	int slidingPuzzle(vector<vector<int>>& board) {
		vector<int> curBoard = { board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2] };//当前谜板
		//0在不同位置可走的map表
		vector<int> moveCnt = { 2, 3, 2, 2, 3, 2 };
		vector<vector<int>> moveMap = { { 1, 3 }, { 0, 2, 4 }, { 1, 5 }, { 0, 4 }, { 1, 3, 5 }, { 2, 4 } };
		int beginPos = 0;
		queue<vector<int>> nextSearchQue;

		for (int i = 0; i<curBoard.size(); i++){
			if (curBoard[i] == 0){
				beginPos = i;
				break;
			}
		}

		if (isCorrectMap(curBoard)){
			//找到了
			return 0;
		}
		//根据movemap广度遍历
		for (int i = 0; i < moveCnt[beginPos]; i++){
			int nTemp = curBoard[beginPos];
			int curKey = vecToMapKey(curBoard);
			vector<int> nextBoardSt;
			for (int j = 0; j < curBoard.size(); j++){
				nextBoardSt.push_back(curBoard[j]);
			}
			nextBoardSt[beginPos] = nextBoardSt[moveMap[beginPos][i]];
			nextBoardSt[moveMap[beginPos][i]] = nTemp;
			nextSearchQue.push(nextBoardSt);
		}
		return findBoard(1, nextSearchQue, moveCnt, moveMap);
	}
- };`### 解题思路
```javascript []
console.log('Hello world!')
```
console.log('Hello world!')
```
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
	map<int, int> allMap;
	bool isCorrectMap(vector<int> curBoard){
		vector<int> rightBoard = { 1, 2, 3, 4, 5, 0 };//正确的谜板
		for (int i = 0; i<6; i++){
			if (curBoard[i] != rightBoard[i]){
				return false;
			}
		}
		return true;
	}
	int vecToMapKey(vector<int> curBoard){
		int nRet = 0;
		for (int i = 0; i<6; i++){
			nRet = curBoard[i] + nRet * 10;
		}
		return nRet;
	}
	int findBoard(int step, queue<vector<int>>& nextSearchQue, vector<int> &moveCnt, vector<vector<int>> &moveMap) {
		int curSize = nextSearchQue.size();
		if (curSize == 0){
			return -1;
		}
		//根据movemap广度遍历
		for (int i = 0; i < curSize; i++){
			vector<int> nextBoardSt = nextSearchQue.front();
			nextSearchQue.pop();
			map<int, int>::iterator iter;
			int calcKey = vecToMapKey(nextBoardSt);
			iter = allMap.find(calcKey);
			if (iter == allMap.end()){//第一次经过
				allMap.insert(pair<int, int>(calcKey, step));
				if (isCorrectMap(nextBoardSt)){
					//找到了
					return step;
				}
				else{
					//找出下一层要遍历的地图
					int beginPos = 0;
					for (int m = 0; m<nextBoardSt.size(); m++){
						if (nextBoardSt[m] == 0){
							beginPos = m;
							break;
						}
					}
					for (int n = 0; n < moveCnt[beginPos]; n++){
						vector<int> tBoardSt;
						for (int j = 0; j < nextBoardSt.size(); j++){
							tBoardSt.push_back(nextBoardSt[j]);
						}
						int nTemp = nextBoardSt[beginPos];
						tBoardSt[beginPos] = nextBoardSt[moveMap[beginPos][n]];
						tBoardSt[moveMap[beginPos][n]] = nTemp;
						calcKey = vecToMapKey(tBoardSt);
						iter = allMap.find(calcKey);
						if (iter == allMap.end()){//第一次经过
							nextSearchQue.push(tBoardSt);
						}
					}
				}
			}
		}

		return findBoard(step + 1, nextSearchQue, moveCnt, moveMap);
	}
public:

	int slidingPuzzle(vector<vector<int>>& board) {
		vector<int> curBoard = { board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2] };//当前谜板
		//0在不同位置可走的map表
		vector<int> moveCnt = { 2, 3, 2, 2, 3, 2 };
		vector<vector<int>> moveMap = { { 1, 3 }, { 0, 2, 4 }, { 1, 5 }, { 0, 4 }, { 1, 3, 5 }, { 2, 4 } };
		int beginPos = 0;
		queue<vector<int>> nextSearchQue;

		for (int i = 0; i<curBoard.size(); i++){
			if (curBoard[i] == 0){
				beginPos = i;
				break;
			}
		}

		if (isCorrectMap(curBoard)){
			//找到了
			return 0;
		}
		//根据movemap广度遍历
		for (int i = 0; i < moveCnt[beginPos]; i++){
			int nTemp = curBoard[beginPos];
			int curKey = vecToMapKey(curBoard);
			vector<int> nextBoardSt;
			for (int j = 0; j < curBoard.size(); j++){
				nextBoardSt.push_back(curBoard[j]);
			}
			nextBoardSt[beginPos] = nextBoardSt[moveMap[beginPos][i]];
			nextBoardSt[moveMap[beginPos][i]] = nTemp;
			nextSearchQue.push(nextBoardSt);
		}
		return findBoard(1, nextSearchQue, moveCnt, moveMap);
	}
};
```