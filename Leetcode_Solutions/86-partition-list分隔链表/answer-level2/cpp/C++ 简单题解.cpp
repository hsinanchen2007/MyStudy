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
    ListNode* partition(ListNode* head, int x) {
        ListNode empty1(0);
        ListNode empty2(0);
        ListNode* dummy1 = &empty1;
        ListNode* dummy2 = &empty2;
        auto node1 = dummy1;
        auto node2 = dummy2;
        while (head != NULL) {
            if (head->val < x) {
                node1->next = head;
                node1 = node1->next;
            } else {
                node2->next = head;
                node2 = node2->next;
            }
            head = head->next;
        }
        node1->next = dummy2->next;
        node2->next = NULL;
        return dummy1->next;
    }
};
```
![image.png](https://pic.leetcode-cn.com/e1ae3b266a6ff990d6c7123656f66571ce7cc3b65e901a11bdb0509e853d0c46-image.png)
