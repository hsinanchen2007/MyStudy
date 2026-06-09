### 解题思路
1.可以把问题分解成：原字符串分解成numRows个新字符串，再重新拼凑成新的字符串。
2.那么问题就变成：每个字符在哪个新串中，在新串的哪个位置。
2.用字符串数组来存放numRows个字符串，则只需确定每个字符在数组的第几个字符串中，即确定每个字符所处的行。而字符位置就是按照原字符串中字符顺序。
3.行号规律为：0,1,2,...,numRows-1,numRows-2,...,0,1,...

### 代码

```cpp
class Solution {
public:
	string convert(string s, int numRows) {
		int s_size = s.size();
		vector <string> position_row(numRows);//存放每行的字符
		string result;
		int i,row;
		if (numRows == 0 || s_size == 0)
			return result;
		if (numRows == 1)
			return s;
		
		row = 0;
		bool flag;//标志位，为true时候row递增；为false时row递减
		for (i = 0; i < s_size; i++) {
			position_row[row].push_back(s[i]);

			//每次row=0,则row开始递增；row=numRows-1时row开始递减
			if (row == numRows-1) {
				flag = false;
			}
			else if (row == 0) {
				flag =true;
			}

			if (flag)
				row++;
			else
				row--;
		}
		
		for (i = 0; i < numRows; i++) {
			result += position_row[i];
		}
		return result;
	}
};
```