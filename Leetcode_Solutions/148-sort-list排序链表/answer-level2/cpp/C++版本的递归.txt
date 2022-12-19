### 解题思路
归并排序

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
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* fast=head->next;
        ListNode* slow=head;
//cut
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* tmp = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(tmp);
        ListNode* h = new ListNode(0);
        ListNode* res=h;
//merge
        while(left!=NULL && right !=NULL){
            if(left->val<right->val){
                h->next=left;
                left=left->next;
            }else{
                h->next=right;
                right=right->next;
            }
            h=h->next;
        }
        h->next=left!=NULL? left:right;
        return res->next;
    }
};
```