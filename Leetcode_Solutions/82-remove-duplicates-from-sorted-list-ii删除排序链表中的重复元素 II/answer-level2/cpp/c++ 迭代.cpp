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
        if(head==NULL||head->next==NULL)return head;
        ListNode dummy(0);
        dummy.next=head;
        auto prev=&dummy;
        auto cur=prev->next;
        while(cur&&cur->next){//处理【1,1】这种测试样例
            bool duplicate=false;
            while(cur->next&&cur->val==cur->next->val){
                auto tmp=cur->next;
                cur->next=cur->next->next;
                delete tmp;
                duplicate=true;
            }
            if(duplicate){
                prev->next=cur->next;
                if(cur)delete cur;
                cur=prev->next;
            }else{
                prev=cur;
                cur=cur->next;
            }
        }
        return dummy.next;
    }
};
```
