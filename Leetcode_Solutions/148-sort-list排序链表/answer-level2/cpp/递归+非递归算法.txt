### 解题思路
此处撰写解题思路

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
    ListNode* sortList(ListNode* head) { // 递归算法
        // 空链表和只有一个结点的链表已经是有序的 Ordered
        if (!head || !head->next) return head;

        ListNode* newHead = sortList(head->next);
        if (head->val <= newHead->val) {
            head->next = newHead;
            return head;
        }

        ListNode *prev = nullptr, *cur = newHead;
        while (cur && head->val > cur->val) { // 寻找插入位置 ...
            prev = cur;
            cur = cur->next;
        }

        prev->next = head;
        head->next = cur;

        return newHead;
    }

    ListNode* sortList2(ListNode* head) { // 非递归算法

        if (!head || !head->next) return head;

        vector<int> v;
        ListNode* p = head;
        while (p) {
            v.push_back(p->val);
            p = p->next;
        }

        sort(v.begin(), v.end());
        
        ListNode *dummyHead = new ListNode(-1), *tail = dummyHead;
        for (int i = 0; i < v.size(); i++) {
            tail->next = new ListNode(v[i]);
            tail = tail->next;
        }
        return dummyHead->next;
    }
};
```