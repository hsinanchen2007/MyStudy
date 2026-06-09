### 解题思路
1，连接vector内多个链表头尾，合成一条链表
2，依次取链表值保存在vector，sort.
3，依次将有序值存回链表

### 代码

```cpp
void addlists(ListNode*& head, ListNode*&it, ListNode*&result, vector<int>&listtemmp)
{
	if (head == NULL)
	{
	}
	else
	{
		head->next = it;
	}
	if (it == NULL)
	{
		return;
	}

	ListNode*last = NULL;
	ListNode*temp = NULL;
	while(it!=NULL)
	{
		listtemmp.push_back(it->val);
		last = it;
		temp = it->next;
		it = temp;
	} 
	result = last;
}

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) 
	{
		 ListNode*head = NULL;
		 ListNode*result = NULL;
		 ListNode*first = NULL;
		 vector<int> listtemp;
		 for (vector<ListNode*>::iterator iter = lists.begin(); iter != lists.end(); ++iter)
		 {
			 if (*iter != NULL)
			 {
				 first = *iter;
				 break;
			 }
		 }
		for (auto it : lists)
		{
			addlists(head,it,result,listtemp);
			head = result;
		}
		//sort<ListNode*>(first, result);
		sort(listtemp.begin(), listtemp.end());
		head = first;
		ListNode*headtemp = NULL;
		for (auto it : listtemp)
		{
			head->val = it;
			headtemp = head->next;
			head = headtemp;
			
		}
		return first;
		

	}

};
```