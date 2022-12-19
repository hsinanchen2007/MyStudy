### 解题思路
尽管是栈操作，但我们可以用vector来实现栈操作，速度会很快

### 代码

```cpp
// class Solution {
// public:
// 	int calPoints(vector<string>& ops) {
// 		int sum = 0;
// 		stack<string> t;
// 		t.push("");
// 		t.push("");
// 		for (auto s : ops) {
// 			if (s == "+") {
// 				string pre1 = t.top(); t.pop();
// 				string pre2 = t.top(); t.push(pre1);
// 				int score = atoi(pre1.c_str()) + atoi(pre2.c_str());
// 				sum += score;
// 				t.push(to_string(score)); continue;
// 			}
// 			if (s == "D") {
// 				int score = 2 * atoi(t.top().c_str());
// 				sum += score;
// 				t.push(to_string(score)); continue;
// 			}
// 			if (s == "C") {
// 				int score = atoi(t.top().c_str());
// 				sum -= score;
// 				t.pop(); continue;
// 			}
// 			else
// 			{
// 				int score = atoi(s.c_str());
// 				sum += score;
// 				t.push(to_string(score));
// 			}
// 		}
// 		return sum;
// 	}
// };

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for (string op : ops) {
            if (op == "+") {
                v.push_back(v.back() + v[v.size() - 2]);
            } else if (op == "D") {
                v.push_back(2 * v.back());
            } else if (op == "C") {
                v.pop_back();
            } else {
                v.push_back(stoi(op));
            }
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};
```