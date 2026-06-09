### 解题思路
我在统计L R后，跳过有两种情况，一种跳过情况是L R不为零且相等，另一种跳过情况L R都为0。这两种情况是在计算L R之后和之前。看其他题解，有个更有技巧的思路，就是每个原句初始的左括号直接跳过。

### 代码

```cpp
class Solution {
public:
	string removeOuterParentheses(string S) {
		if (S.empty()||S.size()<=2) return "";
		stack<char> t;
		string res = "";
		int left = 0, right = 0;
		int push_flag = 0;
		for (auto s : S) {
			push_flag = 1;
			if (!left&&!right) {
				push_flag = 0;
			}
			if (s == '(') left++;
			else right++;
			if (left==right) {
				push_flag = 0;
				left = 0; right = 0;
			}
			if (push_flag) {
				res += s;
			}
		}
		return res;

	}
};

```