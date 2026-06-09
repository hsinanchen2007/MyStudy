思路可以看labuladong大佬的[题解](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/solution/di-gui-si-wei-ru-he-tiao-chu-xi-jie-by-labuladong/)
```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *left = head;
        ListNode *right = left;
        for(int i = 0; i < k; i++) {
            if(right == nullptr) {
                return head;
            }
            right = right->next;
        }
        ListNode *p = reverse(left, right);
        left->next = reverseKGroup(right, k);
        return p;
    }

    // reverse [left, right)
    ListNode* reverse(ListNode *left, ListNode *right) {
        ListNode *pre = nullptr;
        ListNode *cur = left;
        ListNode *nxt = nullptr;
        while(cur != right) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
```
