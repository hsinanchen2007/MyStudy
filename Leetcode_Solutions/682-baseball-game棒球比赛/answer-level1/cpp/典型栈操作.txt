### 解题思路
典型栈操作，同时涉及到字符串与int之间的转换，事实上，题目存在风险的，如果ops第一个就是+，程序是不安全的。

### 代码

```cpp
class Solution {
public:
	int calPoints(vector<string>& ops) {
		int sum = 0;
		stack<string> t;
		t.push("");
		t.push("");
		for (auto s : ops) {
			if (s == "+") {
				string pre1 = t.top(); t.pop();
				string pre2 = t.top(); t.push(pre1);
				int score = atoi(pre1.c_str()) + atoi(pre2.c_str());
				sum += score;
				t.push(to_string(score)); continue;
			}
			if (s == "D") {
				int score = 2 * atoi(t.top().c_str());
				sum += score;
				t.push(to_string(score)); continue;
			}
			if (s == "C") {
				int score = atoi(t.top().c_str());
				sum -= score;
				t.pop(); continue;
			}
			else
			{
				int score = atoi(s.c_str());
				sum += score;
				t.push(to_string(score));
			}
		}
		return sum;
	}
};
```