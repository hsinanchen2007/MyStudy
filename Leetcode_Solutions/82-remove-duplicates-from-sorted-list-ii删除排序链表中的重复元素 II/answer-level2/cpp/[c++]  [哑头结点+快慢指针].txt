```
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) return head;
		ListNode dummy(0);//设置头节点
		dummy.next = head;//连通头节点和给定链表
		ListNode* pre = &dummy;//指向前置节点
		ListNode* curr = head;//指向第一个节点
		while (curr != NULL) {
			while (curr->next != NULL && (curr->val == curr->next->val)) {
				curr = curr->next;//如果下一个节点仍然和这个节点相等，则继续向后移动直至curr指向重复的最后一个节点
			}
			if (pre->next != curr) {//如果存在重复节点
				pre->next = curr->next;//直接指向重复的最后一个结点的下一个节点。
				curr = curr->next;//指针后移
			}
			else {
				curr = curr->next;
				pre = pre->next;
			}
		}
		return dummy.next;
	}
};
```
