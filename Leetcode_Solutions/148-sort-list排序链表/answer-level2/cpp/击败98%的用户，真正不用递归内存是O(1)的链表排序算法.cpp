```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 1. 将从head开始的第len的元素的next设置为NULL
// 2. 返回第len+1个节点指针（这是剪切后第2条链的头节点）
ListNode* cut(ListNode* head, int len)
{
	while (len>1 && head!=NULL)
	{
		len--;
		head = head->next;
	}
	if (head == NULL)
		return NULL;
	ListNode* nextListHead = head->next;
	head->next = NULL;
	return nextListHead;
}

// 合并有序链表
ListNode* mergeSortedList(ListNode* list1Head, ListNode* list2Head)
{
	ListNode dummyHead(0);
	ListNode *resultListEnd=&dummyHead;
	while (list1Head!=NULL&&list2Head!=NULL)
	{
		if (list1Head->val < list2Head->val)
		{
			resultListEnd->next = list1Head;
			list1Head = list1Head->next;
		}
		else
		{
			resultListEnd->next = list2Head;
			list2Head = list2Head->next;
		}
		resultListEnd = resultListEnd->next;
	}

	resultListEnd->next = (list1Head == NULL) ? list2Head : list1Head;
	return dummyHead.next;
}

ListNode* sortList(ListNode* head) {
	
	// 统计链表的长度
	int countLen = 0;
	ListNode* p = head;
	while (p!=NULL)
	{
		countLen++;
		p = p->next;
	}


	int localLen = 1;
	ListNode dummyHead(0);
	dummyHead.next = head;
	ListNode *localHead1, *localHead2,*localHead3;
	while (localLen < countLen) {
		p = &dummyHead;
		localHead3 = dummyHead.next;
		// p是上条链的末尾
		// localHead3是待选链的头节点
		while (localHead3 != NULL) {
			localHead1 = localHead3;
			localHead2 = cut(localHead1,localLen);
			localHead3 = cut(localHead2, localLen);
		
			p->next = mergeSortedList(localHead1, localHead2);

			while (p->next != NULL) {
				p = p->next;
			}
			p->next = localHead3;
		}

		localLen = localLen << 1;
	}
	return dummyHead.next;
}
};
```
