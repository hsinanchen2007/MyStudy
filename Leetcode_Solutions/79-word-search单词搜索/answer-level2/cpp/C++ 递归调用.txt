# C++ 代码：
##    本题采用递归查找下一个位置的字符，具体说明如下：
    递归传入的参数有四个，分别为：
        board ：二维网格；
        X: 网格的横坐标，即二维数组的第一个下标
        Y：网格的纵坐标，即二维数组的第二个下标
        Count:需要匹配的单词下表；
    1、首先是一些递归边界条件的判断：
        包括：查找到单词的最后了，可以直接返回true,
            下标越界，返回false;
            当前字符与单词不匹配，返回false；
    2、接下来考虑单词匹配的情况：
        记录下当前网格的字符，同时由于字符不允许重复使用，可以将当前网格中的字符置为"*",递归之后再将字符变回来。
        然后分别递归判断(X+1,Y),(X-1,Y),(X,Y-1),(X,Y+1),当所有情况都不匹配时，放字符变回来，同时return false;
        否则 return true;
 主调函数遍历所有网格，当当前字符与单词第一个字符匹配时进行递归。
![image.png](https://pic.leetcode-cn.com/a98ab3f592e63ca95a1f53eedc6ad5b37582cf7f2c273aefcc87a1788376cd4a-image.png)

下面附上代码：

```
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		this->X_Size = board.size();
		this->Y_Size = board[0].size();
		this->Word = word;
		this->WordSize = word.size();
		for (int i = 0; i < X_Size; ++i) {
			for (int j = 0; j < Y_Size; ++j) {
				if (board[i][j] == word[0] && IsNext(board,i,j,0)) {
					return true;
				}
			}
		}
		return false;
	}
private:
	int X_Size, Y_Size,WordSize;
	string Word;
	bool IsNext(vector<vector<char>>& board, int X, int Y, int Count)
	{
		if (Count == WordSize) return true;
		if (X < 0 || X >= X_Size) return false;
		if (Y < 0 || Y >= Y_Size) return false;
		char TempChar = board[X][Y];
		if (TempChar != Word[Count]) return false;
		board[X][Y] = '*';
		if (IsNext(board, X + 1, Y, Count + 1) == false &&
			IsNext(board, X - 1, Y, Count + 1) == false &&
			IsNext(board, X, Y - 1, Count + 1) == false &&
			IsNext(board, X, Y + 1, Count + 1) == false){
            		board[X][Y] = TempChar;
             return false;
            }

		board[X][Y] = TempChar;
		return true;
	}

};
```
```
