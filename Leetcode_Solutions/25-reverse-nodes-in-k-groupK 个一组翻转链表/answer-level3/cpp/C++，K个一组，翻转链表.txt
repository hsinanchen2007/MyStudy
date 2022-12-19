### 解题思路
写一个翻转链表函数reverseList。
截取链表前k个节点，翻转，接着将后面剩余的链表节点递归调用reverseKGroup。结束条件：空链表或节点数不足k返回链表本身。

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *pl = head;
        ListNode *pr = head;
        int count = 1;
        while (pr && count < k) {
            pr = pr->next;
            count++;
        }
        if (!pr) return head;
        ListNode *next_ = pr->next;
        pr->next = nullptr;
        ListNode *res = reverseList(pl);
        pl->next = reverseKGroup(next_, k);
        return res;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode dummy(-1);
        ListNode *p1 = head;
        ListNode *p2 = head->next;
        ListNode *p3 = p2;
        p1->next = nullptr;
        while (p3) {
            p2 = p3->next;
            p3->next = p1;
            p1 = p3;
            p3 = p2;
        }
        return p1;
    }
};
```