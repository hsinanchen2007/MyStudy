```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverse(struct ListNode*);

void reorderList(struct ListNode* head){
	
    if( head == NULL || head->next == NULL || head->next->next == NULL)
	{
		return;
	}
	
	struct ListNode *slow = head, *fast = head;
	
	while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	
	struct ListNode *rightHead;
	
	rightHead = reverse(slow->next);
    slow->next = NULL;

	struct ListNode *left = head, *right = rightHead, *leftNext, *rightNext;
	while( right != NULL)
	{
		leftNext = left->next;
		left->next = right;
		left = leftNext;
		rightNext = right->next;
		right->next = left;
		right = rightNext;
	}
    
	return;
}

struct ListNode* reverse(struct ListNode* head)
{
	
	if( head == NULL || head->next == NULL)
	{
		return head;
	}
	
	struct ListNode *pre = NULL, *cur = head, *next = NULL;
	
	while(cur != NULL)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	
	return pre;
		
}
```
一开始我用了很复杂的方式以确保无论奇偶都在中点处断开，而题解里面找中点都非常简单，百思不得其解。
```
struct ListNode *slow = head, *fast = head, *pre = NULL;
	
	while(fast != NULL && fast->next != NULL)
	{
        pre = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	
	if(fast != NULL)
	{
		pre = pre->next;
	}
	
	struct ListNode *rightHead;
	
	rightHead = reverse(pre->next);
    pre->next = NULL;
```
这段代码对于奇数节点链表，找到是中点。对于偶数节点链表找到的是后半部分的首节点。
```
while(fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
```
然后直接断开。
```
rightHead = reverse(slow->next);
    slow->next = NULL;
```

这里对于奇数来说，从中点处断开没有问题。
```
[1,2,3,4,5] [1,2,3] [4,5]
```
但是对于偶数来说，并不是从中间断的。
```
[1,2,3,4] [1,2,3] [4]
```
那么为什么这么可以呢？
因为对于偶数链表来说后半部分的首节点是不需要动的。

一开始没有将前后用链表断开，最后尾节点没有指向next而是指向自己，导致执行代码永远超时。
程序正常运行到return，超时发生在打印链表的过程中。


