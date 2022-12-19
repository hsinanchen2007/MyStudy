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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* last;
    struct ListNode* newlist  = last = NULL;
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
        while(l1 && l2)
        {
            struct ListNode* current = (struct ListNode*)malloc(sizeof (struct ListNode));
            if(l1 -> val >= l2 -> val)
            {
                current -> val = l2 -> val; 
                l2 = l2 -> next;
            }
            else
            {
                current -> val = l1 -> val;
                l1 = l1 -> next;
            }
            current -> next = NULL;
            if(newlist == NULL)
                newlist = current;
            else
                last -> next = current;
            last = current;
        }
        while(l1)
        {
            struct ListNode* current = (struct ListNode*)malloc(sizeof (struct ListNode));
            current -> val = l1 -> val;
            current -> next = NULL;
            if(last)
            last -> next = current;
            last = current;
            l1 = l1 -> next;
        }
        while(l2)
        {
            struct ListNode* current = (struct ListNode*)malloc(sizeof (struct ListNode));
            current -> val = l2 -> val;
            current -> next = NULL;
            if(last) 
            last -> next = current;
            last = current;
            l2 = l2 -> next;
        }
        return newlist;
}
```