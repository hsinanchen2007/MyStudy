先反转链表后，进行一次遍历
```
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(!head) return {};
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur->next){
            ListNode* suc = cur->next;
            cur->next = pre;
            pre = cur;
            cur = suc;
        }
        cur->next = pre;
        
        vector<int> res;
        while(cur){
            res.push_back(cur->val);
            cur = cur->next;
        }
        return res;
    }
};
```
