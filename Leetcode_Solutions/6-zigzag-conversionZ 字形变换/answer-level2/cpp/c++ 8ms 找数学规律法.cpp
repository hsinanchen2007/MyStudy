### 解题思路
把索引号写下来，找一找数字规律，很容易的

### 代码

```cpp
class Solution {
public:
	string convert(string s, int numRows) {
		if ((s.size() == 0)||(s.size()==1)||(numRows==1))return s;
        
		string s1 = "";
		int add = 2 * numRows - 2;
		for (int i = 1; i <= numRows; i++) {
			if (i == 1) {
				for (int k = 0; k * add  <= s.size(); k++) {
					s1 = s1.append(s, k * add , 1);
				}
			}
			else if (i == numRows) {
				for (int k = 0; k * add + numRows -1<= s.size(); k++) {
					s1 = s1.append(s, k * add + numRows-1, 1);
				}
			}
			else {
				for (int k = 0; (k * add + i -1<= s.size()) || (k * add + 2 * numRows - i-1 <= s.size()); k++) {
					if (k * add + i-1 <= s.size()) {
						s1 = s1.append(s, k * add + i-1, 1);
					}
					if (k * add + 2 * numRows - i-1 <= s.size()) {
						s1 = s1.append(s, k * add + 2 * numRows - i-1, 1);
					}
				}
			}
		}
		return s1;
	}
};
```