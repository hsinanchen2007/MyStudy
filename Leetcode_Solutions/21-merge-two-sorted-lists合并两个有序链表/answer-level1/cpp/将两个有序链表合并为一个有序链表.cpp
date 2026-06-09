### 解题思路
    给新链表pc新建头结点，设立指针p指向pc单链表最后一个结点，设立指针pl1、pl2分别指向l1表和l2表当前待比较的插入的结点。若l1->val <= l2->val，则将pl1所指结点链接到p所指结点之后，否则将pl2所指结点链接到p所指结点之后。  
    显然，指针的初始状态为：当l1和l2为非空表时，pl1和pl2分别指向l1和l2表中第一个结点，否则为空；p指向空表pc头结点。  
    由于链表的长度是隐含的，则第一个循环执行的条件是pl1和pl2都非空，当其中一个为空时，说明有一个表的元素已经归并完成，则只要将另一个表的剩余元素链接在p所指结点之后即可。

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
        
        ListNode *pl1,*pl2,*pc,*p;
        pc =new ListNode(0); 
		p=pc;
		pl1=l1;
		pl2=l2;
		while(pl1&&pl2){
			if(pl1->val <=pl2->val){
				p->next=pl1;
				p=pl1;
				pl1=pl1->next;
			}else{
				p->next=pl2;
				p=pl2;
				pl2=pl2->next;
			}
		}
		p->next=pl1?pl1:pl2; 
		return pc->next;
    }
};
```