```
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1); //虚拟头节点
        ListNode* curr = dummy;             //当前节点
        
        while(l1 && l2) {
            if(l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;  //处理下一个
        }
        
        curr->next = l1 ? l1 : l2; //追加剩余部分
        
        return dummy->next;
    }
};
```
