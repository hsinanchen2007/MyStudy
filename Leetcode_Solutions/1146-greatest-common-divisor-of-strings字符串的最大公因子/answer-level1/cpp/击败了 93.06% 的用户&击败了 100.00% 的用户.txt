### 解题思路
先求最大公约数
然后滑窗比较

### 代码

```cpp
//18:48
class Solution {
public:
string gcdOfStrings(string str1, string str2) {
	//if(str1.empty()||str2.empty())return "";
	int size1 = str1.size();
	int size2 = str2.size();
	int min_size = size1 < size2 ? size1 : size2;
	for (int i = min_size;i>0;i--) {
		if ((size1%i == 0) && (size2%i == 0)) {
			string window1(str1, 0, i);
			bool pass = true;
			for (int j = 0; (j + i) <= size2;j += i) {
				string window2(str2, j, i);
				if (window2 != window1) {
					pass = false;
					break;
				}
			}
			if (!pass)continue;
			else pass = true;
			for (int j = i;(j + i) <= size1;j += i) {
				string window2(str1, j, i);
				if (window2 != window1) {
					pass = false;
					break;
				}
			}
			if (!pass)continue;
			return window1;
		}
	}
	return "";
}


};
```