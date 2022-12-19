### 解题思路
快慢指针。

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
    struct ListNode* s = head;
    struct ListNode* f = head;

    while(f && f->next){
        f = f->next->next;
        s = s->next;
    }

    return s;
}
```