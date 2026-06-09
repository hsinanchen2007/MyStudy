### 解题思路
注意观察规律，第一行的第i个点为i*numRows+i*(numRows-2),i为第一行i个点
那么第二行的对应第一行第i个点的左右两点为i*numRows+i*(numRows-2)+/-1
第N行的对应第一行第i个点的左右两点为i*numRows+i*(numRows-2)+/-row
只需要根据第一行的点逐行输入即可

P    I    N
A  L S  I   G
Y A  H R 
P    I

0   6     12
1  5 7   11 13
2 4   8 10
3      9



### 代码

```cpp
class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		string res;
		int row = 0;
		while (row < numRows)
		{
			//逐行加入
			int n = 0;
			while (1)
			{
				if (2 * n*numRows - 2 * n - row >= s.size() && 2 * n*numRows - 2 * n + row >= s.size())
					break;
				if (row == 0)
				{
					res.push_back(s[2 * n*numRows - 2 * n]);
					n++; 
					continue;
				}
				if (row == numRows - 1)
				{
					if (2 * n*numRows - 2 * n + row >= s.size())
						break;
					res.push_back(s[2 * n*numRows - 2 * n + row]);
				}
				else
				{
					if (n * (2 * numRows - 2) - row >= 0)
						res.push_back(s[2 * n*numRows - 2 * n - row]);
					if (n * (2 * numRows - 2) + row < s.size())
						res.push_back(s[2 * n*numRows - 2 * n + row]);
				}
				n++;
			}
			row++;
		}
		return res;
	}
};

```