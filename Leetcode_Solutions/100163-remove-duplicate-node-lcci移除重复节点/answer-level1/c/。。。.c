### 解题思路
方法比较简单，map标记以下即可

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeDuplicateNodes(struct ListNode* head){
    int map[10001] = {0};
    if(head == NULL)
        return head;
    struct ListNode *ptr1 = head;
    struct ListNode *ptr2 = head->next;
    map[ptr1->val] = 1;
    while(ptr2){
        if(map[ptr2->val] == 0){
            map[ptr2->val] = 1;
            ptr1 = ptr2;
            ptr2 = ptr2->next;
        }
        else{
            ptr1->next = ptr2->next;
            ptr2 = ptr1->next;
        } 
    }
    return head;
}
```