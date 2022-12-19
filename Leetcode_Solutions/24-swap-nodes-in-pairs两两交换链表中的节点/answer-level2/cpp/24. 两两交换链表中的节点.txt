解题思路：定义哑节点dummy和临时交换用的point1/2，遍历head链表即可。

执行用时 :8 ms, 在所有 C++ 提交中击败了54.26%的用户
内存消耗 :8.6 MB, 在所有 C++ 提交中击败了86.92%的用户

```c++ []
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *point1 = dummy;
        ListNode *point2 = dummy;
        point2->next = head;
        while (head!=nullptr) {
            head = head->next;
            if (head!=nullptr) {
                point2 = point2->next;

                point1->next = head;
                point2->next = head->next;
                head->next = point2;

                point1 = point1->next->next;
                head = head->next->next;
            }
        }
        return dummy->next;
    }
};
```
