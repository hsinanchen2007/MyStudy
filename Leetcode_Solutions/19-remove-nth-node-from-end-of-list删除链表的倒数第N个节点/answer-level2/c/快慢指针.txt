### 解题思路
此处撰写解题思路
需要另外讨论删除节点是头节点的情况
### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    // if(head->next==NULL) return NULL;
    struct ListNode * fast=head, *slow=head;
    struct ListNode *pre=(struct ListNode*)malloc(sizeof(struct ListNode)), *tmp=pre;
     pre->next=slow;
    while(n--){
        fast=fast->next;
    }
    while(fast){
        fast=fast->next;
        slow=slow->next;
        pre=pre->next;
    }
    if(slow==head){
        head=head->next;
        free(slow);
        free(tmp);
        return head;
    }
    else{
    pre->next=slow->next;
    free(slow);
    free(tmp);
    return head;
    }
}
```