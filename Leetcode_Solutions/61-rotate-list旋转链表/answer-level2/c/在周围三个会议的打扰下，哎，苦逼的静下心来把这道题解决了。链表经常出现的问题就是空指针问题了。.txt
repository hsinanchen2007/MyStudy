### 解题思路
此处撰写解题思路

### 代码
![image.png](https://pic.leetcode-cn.com/05deed611440f08c5aeb8b1b920c0bbd6ad2fe1808b0839f72de037b793a69f2-image.png)

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL) {
        return NULL;
    }

    struct ListNode* bak = head;
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    if (k % len == 0) {
        return bak;
    }

    head = bak;
    struct ListNode *p = head;
    for (int i = 1; i < (len - (k % len) + 1); i++) {
        p = head;
        head = head->next;
    }
    p->next = NULL;

    struct ListNode *res = head;
    while (head->next) {
        head = head->next;
    }
    head->next = bak;

    return res;
}
```