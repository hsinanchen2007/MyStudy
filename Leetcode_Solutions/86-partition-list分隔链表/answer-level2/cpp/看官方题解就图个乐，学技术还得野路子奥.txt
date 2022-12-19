+ 开个玩笑哈，官解还是非常棒的  
> 下面思路也很简单将链表拆成两条链，然后拼接，不过效果一般
```c++
class Solution {
public:
     ListNode* partition(ListNode* head, int x) {
	 if (head == NULL) return head;
	 ListNode*low_x = new ListNode(0), *up_x = new ListNode(0), *cur = head;
	 ListNode* tmp1 = low_x, *tmp2 = up_x;
	 
	 while (cur){//遍历将节点分区
		 if (cur->val<x) { tmp1->next = cur; tmp1 = cur; }
		 else           { tmp2->next = cur; tmp2 = cur; }
		 cur = cur->next;
	 }
	 tmp1->next = NULL;//防止尾部粘连
	 tmp2->next = NULL;

	 tmp1->next = up_x->next;//拼接链表
	 return low_x->next;
 } 
};```