### 解题思路

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
    struct ListNode* p = head;
    int res = 0;
    while(p){
        res=res*2+p->val;
        p=p->next;
    }
    return res;
}
```