### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	bool isWord(char x) {
		return (x >= 'a'&&x <= 'z') || (x >= 'A'&&x <= 'Z');
	
	}
	string reverseOnlyLetters(string S) {
		if (S == "") return "";
		int low = 0;
		int high = S.size() - 1;
		while (low <= high&&!isWord(S[low])) {
			low++;
		}
		while (high >= 0&&!isWord(S[high])) {
			high--;
		}
		while (low<high) {
			char temp = S[low];
			S[low] = S[high];
			S[high] = temp;
			low++;
			high--;
			while (low <= high && !isWord(S[low])) {
				low++;
			}
			while (high >= 0 && !isWord(S[high])) {
				high--;
			}

		}
		return S;
	}
};
```