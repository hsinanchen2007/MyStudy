### 解题思路
slow走一步，fast走两步~当fast走到空指针，返回的slow自然就是中间节点
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *slow = head, *fast = head;
    while (slow->next && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
```