### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户
思路三步走：
1.先翻转num，若得到的num‘比num大，则求比num小的回文数；若得到的num’比num小，则求比num大的回文数；若num==num‘，则同时求大小两个回文数。
2.求大小回文数具体做法是对中间位加减一，然后将头部部分赋值给尾部部分。
3.求大回文数中，多申请一位用来存储进位数，分别判断是否进位的情况；求小回文数中，判断是否出现借位情况，若出现借位，其余位数必全是9；若未出现借位，按正常处理即可；


### 代码

```cpp
class Solution {
public:
	string nearestPalindromic(string n) {
		long num = stol(n);
		long row = rowPalindrmic(n);
		long big = row > num ? row : bigPalindramic(n);
		long small = row < num ? row : smallPalindramic(n);
		return to_string(big - num < num - small ? big : small);
	}
	long rowPalindrmic(string n) {
		long size = n.size();
		for (int i = size - 1; i >= size/2;i--) {
			n[i] = n[size - 1 - i];
		}
		return stol(n);
	}
	long bigPalindramic(string n) {
		string str = "0" + n;
		int size = str.size();
		for (int i = size/2; i >= 0; i--) {
			++str[i];
			if (str[i] > '9') {
				str[i] = '0';
			}
			else {
				break;
			}
		}
		if (str[0] == '1') {
			for (int i = size - 1; i > size/ 2; i--) {
				str[i] = str[size-1-i];
			}
		}
		else {
			for (int i = size - 1; i >size/2; i--) {
				str[i] = str[size-i];
			}
		}
		return stol(str);
	}
	long smallPalindramic(string n) {
		string str = n;
		int size = str.size();
		for (int i = (size - 1) / 2; i >= 0; i--) {
			str[i] -= 1;
			if (str[i] < '0') {
				str[i] = '9';
			}else {
				break;
			}
		}
		if (str[0] == '0') {
			for (int i = 1; i < size;i++) {
				str[i] = '9';
			}
		}
		else {
			for (int i = size - 1; i > (size-1) / 2; i--) {
				str[i] = str[size - 1 - i];
			}
		}
		return stol(str);
	}
};
```