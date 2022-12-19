### 解题思路
//使用队列实现广度优先搜索

### 代码

```cpp
struct node {
	string str;
	int val;
	int canUse1Num;
	node(int n) :str(string()), val(0), canUse1Num(n) {}
	node(string curStr, int curVal, int n) :str(curStr), val(curVal), canUse1Num(n) {}
};

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		deque<node*>myDeque;
		vector<string>ans;
		myDeque.push_back(new node(n));
		while (myDeque.size()) {
			node *cur = myDeque.front();
			myDeque.pop_front();
			if (cur->str.length() == 2 * n) { 
				ans.push_back(cur->str); 
				continue;
			}

			if (cur->val > 0) {
				if (cur->canUse1Num > 0) {
					myDeque.push_back(new node(cur->str + '(', cur->val + 1, cur->canUse1Num - 1));
					myDeque.push_back(new node(cur->str + ')', cur->val - 1, cur->canUse1Num));
				}
				else {
					myDeque.push_back(new node(cur->str + ')', cur->val - 1, cur->canUse1Num));
				}
			}
			else {
				if (cur->canUse1Num > 0) {
					myDeque.push_back(new node(cur->str + '(', cur->val + 1, cur->canUse1Num - 1));
				}
				else {
					continue;
				}
			}
		}
		return ans;
	}
};
```