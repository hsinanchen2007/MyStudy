### 解题思路
头插法。。。

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){


    struct ListNode* newHead = NULL;
    struct ListNode* newnode = NULL;
    
    

    while(head != NULL)
    {
        newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = head->val;
        newnode->next = NULL;
      
        newnode->next = newHead;
        newHead = newnode;
        
        head = head->next;
    }


    return newHead;

}
```