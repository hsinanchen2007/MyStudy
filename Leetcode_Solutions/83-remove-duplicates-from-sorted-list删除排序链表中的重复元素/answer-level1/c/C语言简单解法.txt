### 解题思路
这道题最容易出现问题的地方应该是只想到了1223这种情况而没想到12223的情况，所以正确的方法是要同时考虑两个指针p和p->next

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p = head;
    struct ListNode *tmp;

    while(p != NULL && p->next != NULL){
        if(p->val != p->next->val){
            p = p->next;
        }else{
            tmp = p->next;
            p->next = p->next->next;
            free(tmp); 
        }
    }
    return head;
}
```