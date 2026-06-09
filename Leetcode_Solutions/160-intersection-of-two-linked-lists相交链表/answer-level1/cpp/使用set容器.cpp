思路很简单，首先题目中说明没有环，我们将两个链表的节点都放到set中，如果有公共节点那么插入失败返回该节点，没有公共节点返回NULL
```
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1=headA,*ptr2=headB;
        set<ListNode*> res;
		while(ptr1)
		{
			res.insert(ptr1);
			ptr1=ptr1->next;
		}
		while(ptr2)
		{
			if(res.find(ptr2)!=res.end())
				return ptr2;
			res.insert(ptr2);
			ptr2=ptr2->next;
		}
		return NULL;
    }
};
```
