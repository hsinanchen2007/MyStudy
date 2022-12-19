![1.jpg](https://pic.leetcode-cn.com/682ee3a6d529fc48b70dc6d50885e801dde56b8143140eb0ea7fcd62c3dc6c71-1.jpg)
C++内存消耗8.6M击败100%, 执行用时8ms击败98%
使用二进制存储信息，只使用一个一维数组。

使用一个长度为9的数组记录0-9出现的信息， 每个数用长为27的数记录。
bit 0-8:squart;  //记录数字i是否在第bit[k]个九宫格出现过
bit 9-17: row;   //记录数字i是否在第bit[k]行出现过
bit 18-26: column//记录数字i是否在第bit[k]列出现过

```
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<int> count(9, 0); //分别记录1-9出现的情况 bit 0-8:squart; bit 9-17: row; bit 18-26: column
		for (int i = 0; i < 9; i++){
			for (int j = 0; j < 9; j++){
				int val = board[i][j] - '0';
				int squart_num = int(i / 3) * 3 + j / 3;
				if (val > 0 && val < 10){
					val--;
					if (((count[val] >> squart_num) & 1) || ((count[val] >> (9 + i)) & 1)\
						|| ((count[val] >> (18 + j)) & 1) ) //第squart_num九宫格、第i行、第j列均未出现过
						return false;
					count[val] += (1 << squart_num) + (1 << (i + 9)) + (1 << (j + 18));
				}
			}
		}
		return true;
	}
};
```



