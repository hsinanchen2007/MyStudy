### 解题思路
此处撰写解题思路

### 代码

```cpp
void addlist(list<int>& list, ListNode*&lists)
{
    ListNode* list_temp ;
    if(lists!=NULL)
    {
      list_temp=lists;  
    }
	while (lists !=NULL)
	{
		list.push_back(lists->val);
		lists = list_temp->next;
		list_temp = lists;
	}
};
void foreardl_listtolists(list<int>& list, ListNode*&lists)
{
	ListNode* lists_temp = NULL;
	ListNode* node = NULL;
	for (auto it : list)
	{   
		if (lists_temp != NULL)
		{
			node= new ListNode(it);
			lists_temp->next=node;
			lists_temp = node;
		}
		else
		{
			lists = new ListNode(it);
			lists_temp = lists;
		}
	}
};
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
        ListNode* list_head=NULL;
        if(lists.empty())
        {
            return list_head;
        }
		list<int> list;

		for (auto it : lists)
		{
			addlist(list, it);
		}
		list.sort();
    
		
		foreardl_listtolists(list, list_head);
		return list_head;
	}
};
```