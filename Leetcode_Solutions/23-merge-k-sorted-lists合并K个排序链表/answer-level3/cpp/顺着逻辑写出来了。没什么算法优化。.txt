### 
思路：
1,写一个放一个节点进另一个链表的函数
2,写一个合并两个节点的函数
3,依次合并每条链表
第二个函数需要5个参数。前两个参数是两个正在合并的链表，后两个参数用来储存插入下一个节点时需要的信息。
最后一个参数是用来标记是否满足可以立即退出的条件。参数都是一边写根据需要一边加进去的。
需要注意的是，第一条链表假想为加入到一个空链表上，每一条被加入的链表都会在头部加入一个假想的节点，避免每次都需要检测空指针。
。### 代码

```cpp
void mergenode(ListNode*&d, ListNode*&p, ListNode*&n, ListNode*&l,bool& flag)
{
	if (p->val < d->val)
	{

		l = p;
	}
	else
	{
		l->next = n;
		ListNode* compare = n->next;
		ListNode* compare_temp ;
		ListNode* compare_temp_old=d;
		if (compare == NULL)
		{
			n->next = p;
			flag = true;
			return;
		}

		while (p->val >= compare->val)
		{
			compare_temp = compare->next;
			//d->next = p;
			if (compare_temp== NULL)
			{
				compare->next = p;
				flag = true;
				return;
			}
			compare_temp_old = compare;
			compare = compare_temp;
			
		}
		n = compare;
		l = p;
		compare_temp_old->next = p;
	}
}

ListNode* mergetwolists(ListNode*&list_one, ListNode*&list_two)
{
	if (list_one == NULL)
	{
		return list_two;
	}
	if (list_two == NULL)
	{
		return list_one;
	}
	ListNode virtualnode(1);

	ListNode* p = list_two;
	ListNode* d = list_one;
	ListNode* n=d;
	ListNode* temp_p=p;
	ListNode* l=&virtualnode;
	l->next = p;
	
	while (1)
	{
		bool flag = false;
		
		if (temp_p == NULL)
		{
			p->next = n;
			break;
		}
		p = temp_p;
		d = n;
		mergenode(d, p, n, l,flag);
		if (d == NULL || temp_p == NULL||flag==true)
		{
			break;
		}
		temp_p = p->next;
	}
	return list_one->val > list_two->val ? list_two : list_one;

}


class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* listbase = NULL;
		ListNode* temp_base;
		for (vector<ListNode*>::iterator it = lists.begin(); it != lists.end(); ++it)
		{
			temp_base = mergetwolists(listbase, *it);
			listbase = temp_base;

		}
		return listbase;
	}

};



```