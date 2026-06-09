### 解题思路
链表，链表，链表

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pst;
        pst=l1;
        l1->val+=l2->val;
        bool las;
        las=l1->val/10;
        l1->val=l1->val%10;
    //l1,l2均为非空节点时
    while(l1->next!=NULL&&l2->next!=NULL)
    {
        l1=l1->next;
        l2=l2->next;
        l1->val+=l2->val+las;
        las=l1->val/10;
        l1->val=l1->val%10;
    }
    //l1为空节点时
    while(l2->next!=NULL&&l1->next==NULL)
    {
        l2=l2->next;
        l1->next=new ListNode(l2->val+las);//
        l1=l1->next;
        las=l1->val/10;
        l1->val=l1->val%10;
    }
    //都为空时
    while(las)
    {
        if(l1->next==NULL&&l2->next==NULL)
            l1->next=new ListNode(las);//下一个节点为新开辟的节点并且数据值为las
        else
            l1->next->val+=las;
            l1=l1->next;
            las=l1->val/10;
            l1->val%=10;        
    }
    return pst;
    }
};
```