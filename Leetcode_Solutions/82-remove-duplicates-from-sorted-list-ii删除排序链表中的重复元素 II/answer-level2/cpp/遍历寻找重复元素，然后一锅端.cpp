```
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = ListNode(0);
        dummy.next = head;
        auto pre = &dummy;
        auto curr = pre->next;
        bool n = false;
        while(curr && curr->next){
            if(curr->val == curr->next->val){
                n = true;
            }
            else{
                if(!n){//没有重复节点
                    pre = curr;
                }else{
                    pre->next = curr->next;
                    n = false;
                }
            }
            curr = curr->next;
        }
        if(n){//退出while了但遇到了重复的
            pre->next = curr->next;
        }
        return dummy.next;
    }
};
```
