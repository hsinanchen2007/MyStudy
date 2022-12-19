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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy=new ListNode(0);//优雅处理头节点
        dummy->next=head;
        auto right=dummy;
        for(int i=0;i<n;++i)right=right->next;
        auto left=dummy;
        while(right->next){
            right=right->next;
            left=left->next;
        }
        auto tmp=left->next;
        left->next=left->next->next;
        delete tmp;
        return dummy->next;
    }
};
```
