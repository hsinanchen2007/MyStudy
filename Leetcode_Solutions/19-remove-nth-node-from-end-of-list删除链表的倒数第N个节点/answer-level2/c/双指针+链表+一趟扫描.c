### 解题思路
用双指针思想，n为间隔

### 代码
![1.bmp](https://pic.leetcode-cn.com/c4b0d259bfd6fa23a04ac4518f5633fbef10a65cd9f1c27cc0ac55093f92cebd-1.bmp)

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* cur, *tmp, *del;
    int i;

    cur = head;
    tmp = head;
    del = head;

    if (n == 0) {
        return head;
    }
    for (i = 1; i < n; i++) {
        tmp = tmp->next;
    }

    while (tmp != NULL) {
        //printf("%d,%d,%d\n", cur->val, del->val, tmp->val);
        if (tmp->next == NULL) {
            if (cur == head && del == head) {
                head = cur->next;
            } else {
                cur->next = del->next;
                //free(del);
            }
            break;
        } else {
            cur = del;
            del = del->next;
            tmp = tmp->next;
        }
    }

    return head;
}
```