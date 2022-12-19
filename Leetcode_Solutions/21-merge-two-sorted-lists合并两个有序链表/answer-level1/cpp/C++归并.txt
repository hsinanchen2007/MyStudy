### 解题思路
应该注意到题目给的链表是没有头结点的，

### 代码

```cpp
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) { 
        ListNode * l=new ListNode(0);
        ListNode * p3=l;
        while(NULL != l1 && NULL != l2){
	        if (l1->val >= l2->val)
			{
				p3->next = l2; l2 = l2->next; p3=p3->next;
			}
			else 
			{
				p3->next = l1; l1 = l1->next; p3=p3->next;
			}
        }
        if(l1!=NULL) p3->next=l1;//这两行必须要有，否则最后会有一个链表的节点遗漏。
        if(l2!=NULL) p3->next=l2;//
		return l->next;
    }
};
```