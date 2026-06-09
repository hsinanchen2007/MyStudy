### 解题思路
此处撰写解题思路

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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next) return head; 
        ListNode* a=head;
        ListNode* q=a->next;
        ListNode* cur;
        while(q){
            cur=new ListNode(0);
            cur->next=head;
            ListNode* p=head;
            int flag=0;
            while(p!=q){
                if(q->val<p->val){
                    a->next=q->next;
                    cur->next=q;
                    q->next=p;
                    if(p==head) head=cur->next;
                    flag=1;
                    break;
                }
                cur=cur->next;
                p=p->next;
            }
            if(flag==1) q=a->next;
            else {
                a=a->next;
                q=q->next;
            }
        }
        return head;
    }
};
```