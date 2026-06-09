解题思路：遍历pushed中的数据，依次压入辅助栈中，同时全局变量erasei从0开始。如果遇到辅助栈的栈顶数据和popped的数据相等时，erasei加1，相当于popped的下标后移，当下标移动到popped的最后一个数据之后并且辅助栈为空时，返回true。
```
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		stack<int>stData;
		int len = pushed.size();
		if (len <= 2)return true;
		int erasei = 0;
		for (int i = 0; i < len; ++i) {
			stData.push(pushed[i]);
			if (stData.top() == popped[erasei]) {
				while (!stData.empty()&&(stData.top() == popped[erasei])) {
					stData.pop();
					erasei++;
				}
			}
		}
		if (stData.empty() && erasei == len)return true;
		return false;
    }
```
