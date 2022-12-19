### 解题思路
快慢指针实现，以两倍的速度获取中间的值。

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
    struct ListNode *p = head, *q = head;
    while(q -> next != NULL && q -> next -> next != NULL) {
        p = p -> next;
        q = q -> next -> next;
    }

    if (q -> next != NULL && q -> next -> next == NULL) {
        p = p -> next;
    }

    return p;
}
```