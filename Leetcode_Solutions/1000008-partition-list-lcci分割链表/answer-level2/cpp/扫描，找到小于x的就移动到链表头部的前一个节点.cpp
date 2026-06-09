代码里写繁了，可以不用在head前新建节点，直接把后面的符合要求的节点的next指针指向head，再让head等于该节点就行。
```C++ []
class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode* nhead =new ListNode(-1);	//记录要插入位置的前一个位置
		nhead->next = head;
		ListNode* cur = head;	//扫描指针
		ListNode* prev = nhead;	//紧跟着cur的指针，用来删除cur指向的元素
		while (cur) {
			if (cur->val < x && cur != head) {
				prev->next = cur->next;
				cur->next = head;
				nhead->next = cur;
				head = cur;
				cur = prev->next;

			}
			else {
				cur = cur->next;
				prev = prev->next;
			}
		}
		return nhead->next;
	}
};
```
