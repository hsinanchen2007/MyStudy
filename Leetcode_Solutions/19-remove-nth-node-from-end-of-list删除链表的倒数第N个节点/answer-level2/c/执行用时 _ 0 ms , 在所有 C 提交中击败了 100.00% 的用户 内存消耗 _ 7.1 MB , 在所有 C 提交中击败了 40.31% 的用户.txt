### 解题思路
快慢指针。快指针fast前移 n+1，慢指针slow开始移动。当 fast == NULL 时, slow->next 即为要删除的节点。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode *slow = dummy, *fast = dummy;
    for (int i = 0; i <= n; ++i) fast = fast->next;
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}


```