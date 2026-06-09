递归解法

```
class Solution {
   public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // 先检查剩余的节点树是否大于k
        ListNode* p = head;
        int count = k;
        while (p && count) {
            count--;
            p = p->next;
        }
        if (count > 0) return head;

        // 反转k个节点
        ListNode* pre = NULL;
        p = head, count = k;
        while (count--) {
            ListNode* temp = p->next;
            p->next = pre;
            pre = p;
            p = temp;
        }

        // 递归反转剩下的节点
        head->next = reverseKGroup(p, k);
        return pre;
    }
};
```
