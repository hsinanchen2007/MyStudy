### 解题思路
这个题目关键就是能以长度作为递归结束条件，这个很难想到

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
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* cur =head;
        int len = 0;
        while (cur) {
            len++;
            cur = cur->next;
        }
        helper(head, len);
    }

    ListNode* helper(ListNode* head, int len) {
        if (len == 1) {
            return head;
        } else if (len == 2) {
            return head->next;
        } else {
            // 每次需要减，因为去掉了头和尾两个节点
            ListNode* tail = helper(head->next, len-2);
            ListNode* th = head->next;
            head->next = tail->next;
            ListNode* tt = tail->next->next;
            tail->next->next = th;
            // tail其实不会变的，只是每次让它的next指向更外层的节点
            // 一顿操作之后把tail后面的都调整到前面，就结束了
            tail->next = tt;
            return tail;
        }
    }
};
```