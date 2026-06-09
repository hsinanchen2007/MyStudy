```
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* p = head;
		ListNode* t = head;
		vector<int>temp;
		int a = m - 1, b = n;
		int x = m, y = n;
		if (a > 0) {
			while (a--) {
				p = p->next;
				t = t->next;
			}
		}
		while (m++ <= b) {
			temp.push_back(p->val);
			p = p->next;
		}

		int cnt = 0;
		for (int i = x; i <= y; i++) {
			t->val = temp[temp.size() - (cnt++) - 1];
			t = t->next;
		}

		return head;
	}
};
```
![微信截图_20191210232118.png](https://pic.leetcode-cn.com/ef14d67dee87de1befe106e15563bb6ed6fb0f162e76f6b1e02ffae3295b5d32-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191210232118.png)
