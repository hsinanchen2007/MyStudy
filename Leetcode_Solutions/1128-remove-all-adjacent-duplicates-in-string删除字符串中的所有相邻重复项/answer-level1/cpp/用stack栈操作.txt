### 解题思路
典型的栈思想，遇到与栈顶相同的字符串，弹出栈，最后栈中剩余的字符串即为结果。  实际上，不一定要用stack来实现栈操作，因为这样最后输出结果时还得翻转。参考其他题解，我们直接在string上做操作，遇到与back()相同的字符，则弹出back(). 这样最终得出的结果不需要再翻转。

### 代码

```cpp
class Solution {
public:
	string removeDuplicates(string S) {
		string res;
		stack<char> t;
		for (auto s : S) {
			if (t.empty()) {
				t.push(s);
				continue;
			}
			if (t.top() == s) {
				t.pop();
			}
			else
			{
				t.push(s);
			}
		}
		while (!t.empty())
		{
			res += t.top();
			t.pop();
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
```