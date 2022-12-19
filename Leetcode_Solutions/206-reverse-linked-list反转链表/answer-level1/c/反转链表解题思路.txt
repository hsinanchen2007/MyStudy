### 解题思路
从链表尾开始申请内存拷贝，输入到达链表尾停止并输出结果。

### 代码

```c
/**
 * Definition for singly-linked list.
   struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *p1 = head;
    struct ListNode *p2 = NULL;
    struct ListNode *p3 = NULL;
    
    if (p1 == NULL) {
        return NULL;
    }
    
    p2 = malloc(sizeof(struct ListNode));
    p2->next = NULL;

    while(p1 != NULL) {
        p2->val = p1->val;
        p1 = p1->next;
        if (p1 == NULL) {
            break;
        }
        p3 = malloc(sizeof(struct ListNode));
        p3->next = p2;
        p2 = p3;
    }

    return p2;
}
```