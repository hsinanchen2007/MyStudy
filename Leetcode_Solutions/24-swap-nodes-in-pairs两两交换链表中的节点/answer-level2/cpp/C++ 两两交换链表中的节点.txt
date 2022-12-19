### 代码

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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return head;
        ListNode* p1=head,*p2,*pre=head;
        head=head->next;
        while(p1 && p1->next)
        {
            p2=p1->next;
            pre->next=p2;
            p1->next=p2->next;
            p2->next=p1;
            pre=p1;
            p1=p1->next;
        }
        return head;
    }
};