执行用时 :8 ms, 在所有 C++ 提交中击败了99.52%的用户 内存消耗 :9.7 MB, 在所有 C++ 提交中击败了65.91%的用户
```
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* p=head;
        while(p){
            if(p->val==-3)
                return true;
            else
                p->val=-3;
            p=p->next;
        }
        return false;
    }
};
```
