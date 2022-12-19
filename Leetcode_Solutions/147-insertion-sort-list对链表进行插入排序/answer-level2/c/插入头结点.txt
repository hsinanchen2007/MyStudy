### 解题思路
先将链表拆开，对于后面链表的每个开头，在前面的链表中查找其插入位置位置，为了不区分头结点，于是先插入一个头结点，最后返回的时候将头结点释放掉。时间复杂度平方，空间复杂度常数。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* insertionSortList(struct ListNode* head) {
	if (!head || !head->next)
		return head;
	struct ListNode *H = (struct ListNode*)malloc(sizeof(struct ListNode));//插入头结点
	H->next = head;
	H->val = 0;
	head = H;
	struct ListNode *after = head->next->next;
	struct ListNode *prescan = head;
	struct ListNode *scan = prescan->next;
	scan->next = NULL;
	while (after)
	{
		prescan = head;
		scan = prescan->next;//有序链表的工作指针每次都是从头开始扫描
		while (scan)
		{
			if (after->val <= scan->val)
			{
				struct ListNode *temp = after;
				after = after->next;
				temp->next = scan;
				prescan->next = temp;
				break;
			}
			prescan = scan;
			scan = scan->next;
		}
		if (!scan)//应当插入到有序链表尾部的时候
		{
			struct ListNode *temp = after;
			after = after->next;
			temp->next = scan;
			prescan->next = temp;
		}
	}
	after = head->next;
	free(head);//释放掉头结点
	return after;
}
```