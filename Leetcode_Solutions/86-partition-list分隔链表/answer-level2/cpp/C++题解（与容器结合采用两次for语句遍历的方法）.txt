class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* phead = head;
		int len = 0;
		vector<int> vec;
		while (phead != NULL)
		{
			len++;
			vec.push_back(phead->val);
			phead = phead->next;
		}
		ListNode* h = new ListNode(0);
		ListNode* p1 = h;
		for (int i = 0; i < len; ++i)
		{
			if (vec[i] < x)
			{
				ListNode* node = new ListNode(vec[i]);
				p1->next = node;
				p1 = node;
			}
		}
		for (int i = 0; i < len; ++i)
		{
			if (vec[i] >= x)
			{
				ListNode* node = new ListNode(vec[i]);
				p1->next = node;
				p1 = node;
			}
		}
		return h->next;
    }
};