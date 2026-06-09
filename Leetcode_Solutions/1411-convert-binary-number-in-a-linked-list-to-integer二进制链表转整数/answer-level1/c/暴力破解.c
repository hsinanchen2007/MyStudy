### 解题思路
此处撰写解题思路
1.考虑边界条件。
2.计算链表的长度.
3.根据长度计算2的阶层j.
4.sum += head->val * j;
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


int getDecimalValue(struct ListNode* head){
    struct ListNode *newhead;
    int j, k;
    if (head == NULL) {
        return 0;
    }
    int sum = 0;
    if (head->next == NULL && head->val == 0) {
        sum = 0;
        return sum;
    } else if (head->next == NULL && head->val == 1) {
        sum = 1;
        return sum;
    }
    j = 1;
    int length = 1;
    for (newhead = head->next; newhead != NULL; newhead = newhead->next) {
        length++;
    }
    printf("lenght=%d\n",length);
    newhead = head;
    k = length;
    while (newhead != NULL) {
        for (k = length, j = 1; k > 0; k--) {
            j *= 2;
        }
        j /= 2;
        printf("newhead->val = %d, j = %d\n", newhead->val, j);
        if (newhead->val != 0) {
            sum += newhead->val * j;
            printf("sum = %d\n", sum);
        }
        newhead = newhead->next;
        length--;
    }
    return sum;
}
```