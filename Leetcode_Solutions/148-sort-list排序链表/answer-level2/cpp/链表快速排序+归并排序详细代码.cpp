快速排序：
```cpp
class Solution
{
public:

	ListNode* partition(ListNode* head, ListNode* tail)
	{
		int pivot = head->val;
		/*p1及前面的节点值都小于pivot，p2往后走*/
		ListNode* p1 = head, *p2 = head->next;
		while (p2 != tail)
		{
			/*p2遇到值小于pivot的节点，就把它交换到p1下一个位置*/
			if (p2->val < pivot)
			{
				p1 = p1->next;
				swap(p1->val, p2->val);
			}
			p2 = p2->next;
		}
		swap(head->val, p1->val);
		return p1;
	}

	void quickSort(ListNode* head, ListNode* tail)
	{
		if (head != tail)
		{
			ListNode* mid = partition(head, tail);
			quickSort(head, mid);
			quickSort(mid->next, tail);
		}
	}

	ListNode* sortList(ListNode* head)
	{
		quickSort(head, nullptr);
		return head;
	}
};
```
归并排序：
```cpp
class Solution
{
public:
    /*两个有序链表合并*/
	ListNode* merge(ListNode* p1, ListNode* p2)
	{
		ListNode* tmphead = new ListNode(-1);	//加一个虚拟头结点
		ListNode* p = tmphead;
		while (p1 && p2)
		{
			if (p1->val < p2->val)
			{
				p->next = p1;
				p1 = p1->next;
			}
			else
			{
				p->next = p2;
				p2 = p2->next;
			}
			p = p->next;
		}
		p->next = p1 ? p1 : p2;
		
		p = tmphead->next;
		delete tmphead;		//delete
		return p;
	}
    
    /*归并排序*/
	ListNode* sortList(ListNode* head)
	{
		if (!head || !head->next)
		{
			return head;
		}
        /*先找到链表中间节点*/
		ListNode* p_slow = head;
		ListNode* p_fast = head->next->next;
		while (p_fast && p_fast->next)
		{
			p_fast = p_fast->next->next;
			p_slow = p_slow->next;
		}
        /*两半分别排序*/
		ListNode* p1 = sortList(p_slow->next);
		p_slow->next = nullptr;
		ListNode* p2 = sortList(head);
        /*合并*/
		return merge(p1, p2);
	}
};
```