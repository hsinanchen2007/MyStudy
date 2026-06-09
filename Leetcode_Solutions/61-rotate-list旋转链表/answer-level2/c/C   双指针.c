### 解题思路
1. 按注释理解思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 双指针思想
struct ListNode* rotateRight(struct ListNode* head, int k)
{
    if (k <= 0) {
        return head;
    }

    if (head == NULL) {
        return NULL;
    }

    // 1.统计链表长度len
    int len = 1;
    struct ListNode *p = head;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }

    int m = k % len;
    if (m == 0) {
        return head;
    } 
    // 2. p1先移动m步
    struct ListNode *p1 = head;
    for (int i = 0; i < m; i++) {
            p1 = p1->next;
    }

    // 3. 定位到倒数第m个node
    struct ListNode *p2 = head;
    while (p1->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }

    // 4.从p2处断开，后面的指向head即可
    struct ListNode *pRotate = p2->next;
    p2->next = NULL;

    struct ListNode *p3 = pRotate;
    while (p3->next != NULL) {
        p3 = p3->next;
    }
    p3->next = head;
    return pRotate;
}
```