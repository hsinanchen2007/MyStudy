### 解题思路
先计算有多少个节点
根据for循环进行比对。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int kthToLast(struct ListNode* head, int k){
    struct ListNode *newhead;
    int count = 0;
    int i;
    if (head == NULL) {
        return NULL;
    }
    for (newhead = head; newhead != NULL; newhead = newhead->next) {
        count++;
    }
    newhead = head;
    for (i = 0; i < count; i++) {
        printf("k=%d, count=%d, i=%d\n", k, count, i);
        if (k == (count - i)) {
            printf("0 newhead->val=%d\n", newhead->val);
            return newhead->val;
        }
        newhead = newhead->next;
    }
    printf("1 newhead->val=%d\n", newhead->val);
    return newhead->val;
}
```