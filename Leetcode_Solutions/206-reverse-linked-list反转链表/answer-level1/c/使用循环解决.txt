### 解题思路
利用链表的头插法可以实现此功能

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
   if (head != NULL) {
		struct ListNode* newHead = head;
		struct ListNode* tail = head;
		struct ListNode* p = head->next;
		while (p != NULL) {
			struct ListNode* temp = p;
			p = p->next;
			temp->next = newHead;
			newHead = temp;
		}
		tail->next = NULL;
		return newHead;
	}
	else {
		return head;
	}
}
```