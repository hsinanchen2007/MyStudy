很常规的题目
```
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode *p=head->next, *pre=head, *q;
        while(p){
            if(p->val == pre->val){
                q=p;
                p=p->next;
                pre->next=p;
                //delete(q); //为了提高速度可以不释放空间
            }
            else{
                p=p->next;
                pre=pre->next;
            }
        }
        return head;
    }
};
```