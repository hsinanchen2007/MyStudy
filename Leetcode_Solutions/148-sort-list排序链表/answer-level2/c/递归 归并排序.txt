执行用时 : 12 ms, 在所有 c 提交中击败了100.00%的用户
内存消耗 : 9.9 MB, 在所有 c 提交中击败了96.67%的用户
```
struct ListNode* sortListCore(struct ListNode*, int);

struct ListNode* sortList(struct ListNode* head){
    
	if((head == NULL) || (head->next == NULL))
	{
		return head;
	}
	
	struct ListNode *ptr;
	int size;
	
	ptr = head;
	
	for(size = 0; ptr != NULL; ptr = ptr->next, size++);
	
	return sortListCore(head, size);
}

struct ListNode* sortListCore(struct ListNode* head, int size)
{
	
	if(size == 1)
	{
		return head;
	}

	struct ListNode *first, *second, *ptr, *returnList;
	
	first = head;
	ptr = head;
	
	for(int i = 1; i < size/2; ptr = ptr->next, i++);
	second = ptr->next;
    ptr->next =NULL;

	first = sortListCore(first, size/2);

	second = sortListCore(second, (size + 1)/2);

	if(first->val <= second->val)
	{
		returnList = first;
		first = first->next;
	}
	else
	{
		returnList = second;
		second = second->next;
	}

	ptr = returnList;

	while((first != NULL) && (second != NULL))
	{
		if(first->val <= second->val)
		{
			ptr->next = first;
			first = first->next;
		}
		else
		{
			ptr->next = second;
			second = second->next;
		}
		ptr = ptr->next;
	}
 
	ptr->next = (first != NULL ? first : second);
	return returnList;
    
}
```
一开始没有用NULL把链表断开，导致最后的while循环无法终止。

不过我不是很清楚，在递归调用中，没有分配内存，空间复杂度是怎么算的。栈的空间算不算进去。