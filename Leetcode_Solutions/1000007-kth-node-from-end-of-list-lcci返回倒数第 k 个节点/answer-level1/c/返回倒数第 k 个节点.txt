### 解题思路
不是很好的方案，如果做到动态申请内存运行时间也会边长

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
    if(head == NULL) {
        return 0;
    }
    int record[1000] = {0};
    struct ListNode* cur = head;
    int i = 0;
    while(cur != NULL) {
        record[i++] = cur->val;
        cur = cur->next;
    }
    if(i >= k) {
        return record[i-k];
    }
    return 0;
}
```