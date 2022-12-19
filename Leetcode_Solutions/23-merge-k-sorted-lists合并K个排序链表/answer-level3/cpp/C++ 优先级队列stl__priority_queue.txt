
```
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int len = lists.size();
		if (len == 0) return NULL;
		for (int i = 0; i < len; i++) {
			if (lists[i] == NULL) continue;
			temp.push(queueNode(lists[i]->val, i));
		}
		
		ListNode* res = new ListNode(NAN);
		ListNode* p = res;

		queueNode tempQode(NAN,NAN);
		while (!temp.empty()) {
			tempQode = temp.top();
			temp.pop();
			p->next = lists[tempQode.index];
			lists[tempQode.index] = lists[tempQode.index]->next;
			p = p->next;
			p->next = NULL;
			if (lists[tempQode.index] == NULL) continue;
			temp.push(queueNode(lists[tempQode.index]->val, tempQode.index));
			
		}

		return res->next;
	}
private:
	struct queueNode {
		int val;
		int index;
		queueNode(int x, int y) :val(x), index(y){}
	};

	class cmp {
	public:
		bool operator()(queueNode &a, queueNode &b) const {
			return a.val > b.val;
		}

	};
	priority_queue<queueNode, vector<queueNode>, cmp> temp; //小顶堆
};
```