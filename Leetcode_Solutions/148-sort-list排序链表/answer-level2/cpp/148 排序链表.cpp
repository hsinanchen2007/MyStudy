### 解题思路
1.链表分割，快慢指针
pre->next = NULL;
2.排序链表合并
递归 or 循环
### 代码

```cpp
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* quick = head;
        ListNode* pre = head;
        while (quick && quick->next) {
            pre = slow;
            slow = slow->next;
            quick = quick->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    ListNode* merge(ListNode* l, ListNode* r) {
        if (!l) return r;
        if (!r) return l;
        if (l->val < r->val) {
            l->next = merge(l->next, r);
            return l;
        }
        r->next = merge(l, r->next);
        return r;
    }
    ListNode* merge1(ListNode* l, ListNode* r) {
        if (!l) return r;
        if (!r) return l;
        ListNode* cur = new ListNode(0);
        ListNode* head = cur;
        while (l || r) {
            if (!l) {
                cur->next = r;
                break;
            } else if (!r) {
                cur->next = l;
                break;
            } else if (l->val < r->val) {
                cur->next = l;
                l = l->next;
            } else {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
            cur->next = NULL;
        }
        cur = head->next;        
        delete head;
        return cur;
    }
};
```