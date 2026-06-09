```
class Solution {
public:
	bool judgeCircle(string moves) {
		int row = 0;
		int col = 0;
		for (auto c : moves)
		{
			if (c == 'R')
				row++;
			if (c == 'L')
				row--;
			if (c == 'U')
				col++;
			if (c == 'D')
				col--;
		}
		if (col == 0 && row == 0)
			return true;
		return false;
	}
};
```
