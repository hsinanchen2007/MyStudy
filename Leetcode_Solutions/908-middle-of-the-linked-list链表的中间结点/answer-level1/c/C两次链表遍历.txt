### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* tmp = head;
    int count = 1, i = 0;
    while(tmp->next != NULL){
        tmp = tmp->next;
        count++;
    }
        
    count /= 2;
    tmp = head;
    for(i = 0; i < count; i++){
        tmp = tmp->next;
    }
    return tmp;
        
}
```