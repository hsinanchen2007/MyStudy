### 解题思路
使用题目解答中的动态规划，先讨论是否为****()，再讨论是否为(****)
### 代码

```cpp
class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() <= 1) return 0;
		int len = s.size();
		vector<int> temp(len, 0); // 初始化为0
		if (s[1] == ')' && s[0] == '(') temp[1] = 2;
		for (int i = 2; i < len; i++){
			if (s[i] == '(') continue;
			else{
                int a =i - temp[i - 1] - 1;
				if (s[i - 1] == '(') temp[i] = temp[i - 2]+2; // 先判断***()
				else if (i - temp[i - 1]>0 && s[a] == '('){ // 再判断(***)
					if (a== 0){
						temp[i] = temp[i - 1] + 2;
					}
					else{
						temp[i] = temp[i - 1] + 2 + temp[a-1];
					}
				}
			}
		}
		int result = temp[0];
		for (int i = 1; i < len; i++){
			//cout << temp[i] << " ";
			if (result < temp[i]) result = temp[i];
		}
		return result;
	}
};
```