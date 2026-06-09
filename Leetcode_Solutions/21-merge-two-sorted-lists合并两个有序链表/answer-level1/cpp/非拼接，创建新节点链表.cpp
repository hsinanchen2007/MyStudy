```
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1)return l2;
		if (!l2)return l1;
		vector<int> vec = {};
		while (l1!=NULL)
		{
			vec.push_back(l1->val);
			l1 = l1->next;
		}
		while (l2 != NULL)
		{
			vec.push_back(l2->val);
			l2 = l2->next;
		}
		sort(vec.begin(), vec.end());
		int len = vec.size();
		ListNode* p=new ListNode(vec[0]);
		ListNode* head = p;
		for (int i = 1; i < len; i++)
		{
			ListNode* newNode = new ListNode(0);
			newNode->val = vec[i];
			p->next = newNode;
			p = p->next;

		}
		return head;
	}
};
```
