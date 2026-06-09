### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> res;
		while (head != NULL) {
			res.push_back(head->val);
            head = head->next;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};
```