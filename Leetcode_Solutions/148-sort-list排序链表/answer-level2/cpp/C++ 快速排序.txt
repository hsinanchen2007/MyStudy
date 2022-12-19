```
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
    void swap(ListNode* p1, ListNode* p2) {
        if (p1->val == p2->val) return;
        p1->val ^= p2->val;
        p2->val ^= p1->val;
        p1->val ^= p2->val;
    }
    void quickSort(ListNode* left, ListNode* right) {
        if (left == right || left == NULL || right == NULL) return;
        int t = right->val;
        ListNode* prev = NULL;
        ListNode* curr = left;
        ListNode* p = left;
        while (p != right) {
            if (p->val < t) {
                swap(curr, p);
                prev = curr;
                curr = curr->next;
            }
            p = p->next;
        }
        if (curr != right) {
            swap(curr, right);
            curr = curr->next;
        }
        quickSort(left, prev);
        quickSort(curr, right);
    }
    ListNode* sortList(ListNode* head) {
        ListNode* tail = head;
        while (tail != NULL && tail->next != NULL) {
            tail = tail->next;
        }
        quickSort(head, tail);
        return head;
    }
};
```

![image.png](https://pic.leetcode-cn.com/24008dde3ab83dc85be5dada9b003dd51f3a195fae9e3f0caa3b11724e09c3a5-image.png)
