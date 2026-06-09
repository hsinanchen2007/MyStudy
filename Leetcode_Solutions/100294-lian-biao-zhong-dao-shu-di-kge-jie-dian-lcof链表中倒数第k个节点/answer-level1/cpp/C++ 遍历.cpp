```c++
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int n = getSize(head);
        int c = n - k;
        while (c--) {
            head = head->next;
        }
        return head;
    }

    int getSize(ListNode* head) {
        int n = 0;
        while (head) {
            head = head->next;
            n++;
        }
        return n;
    }
};
```