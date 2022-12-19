### 解题思路
核心思路：按位相加，记得加前一级的进位
注意：加到两指针均为空时，再检查一下进位是否为0，否则高位还得有个1
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
        ListNode*p=l1;
        ListNode*q=l2;
        ListNode*r=new ListNode(0);
        ListNode*head=r;
        int add=0;
        while(p!=NULL||q!=NULL){
            if(p==NULL){
                r->next=new ListNode((q->val+add)%10);
                add=(q->val+add)/10;
                r=r->next;
                q=q->next;
                continue;
            }
            if(q==NULL){
                r->next=new ListNode((p->val+add)%10);
                add=(p->val+add)/10;
                r=r->next;
                p=p->next;
                continue;
            }
            r->next=new ListNode((p->val+q->val+add)%10);
            add=(p->val+q->val+add)/10;
            r=r->next;
            p=p->next;
            q=q->next;
        }
        if(add!=0){
           r->next=new ListNode(add);
        }
        return head->next;
    }
};
```