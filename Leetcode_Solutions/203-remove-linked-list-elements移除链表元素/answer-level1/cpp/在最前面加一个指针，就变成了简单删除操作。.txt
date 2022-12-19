![1572537574(1).png](https://pic.leetcode-cn.com/c1af174bc0a7280d0df1b82a9501a4f4d482bba297c76014cb89b446cc16b98c-1572537574\(1\).png)

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head==NULL) return NULL;
        ListNode* prehead = new ListNode(-1);
        prehead->next = head;
        
        ListNode* cur=prehead;
        while(cur && cur->next){
            if(cur->next->val == val) cur->next = cur->next->next;
            else cur = cur->next;
        }
        head = prehead->next;
        delete prehead;
        prehead=NULL;
        return head;
    }
};