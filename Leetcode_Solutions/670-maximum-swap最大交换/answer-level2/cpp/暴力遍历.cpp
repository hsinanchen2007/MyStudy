### 解题思路
交换当前字符与该字符之后的最大字符然后返回。没有的话就返回原来的int 暴力遍历居然双100% 2333

执行用时 :
0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :
6.2 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
	int maximumSwap(int num) {
		string str = to_string(num);
		for (int i = 0; i < str.length(); i++) {
			int max = str[i], index = i;
			bool flag = false;//flag用来记录之后有没有做过交换 只需要一次交换就可以返回
			for (int j = str.length() - 1; j  > i ; j--) {
				if (max <str[j]) {//由于是从后往前所以如果str[i] == str [j]不交换
					max = str[j];
					index = j;
					flag = true;
				}
			}
			if (flag) {
				char tmp = str[index];
				str[index] = str[i];
				str[i] = tmp;
				return stoi(str);
			}
		}
		return num;	
	}
};
```