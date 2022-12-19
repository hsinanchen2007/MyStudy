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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        auto dummy=new ListNode(INT_MIN);
        dummy->next=head;
        auto cur=head->next;
        head->next=NULL;
        while(cur){
            auto pNext=cur->next;
            auto p=dummy;
            while(p->next){//找到插入点
                if(p->next->val>cur->val){
                    cur->next=p->next;
                    p->next=cur;
                    break;               
                }
                p=p->next;
            }
            if(p->next==NULL){//插入点可能在队尾
                p->next=cur;
                cur->next=NULL;
            }
            cur=pNext;
        }
        return dummy->next;
    }
};
```
