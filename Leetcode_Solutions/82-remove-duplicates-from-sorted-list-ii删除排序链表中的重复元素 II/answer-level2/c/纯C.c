### 解题思路
快慢指针

### 代码

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode LNode, *LinkList;

struct ListNode* deleteDuplicates(struct ListNode* head){
    if ( head == NULL )
    {
        return NULL;
    }
    
    LNode dummyNode;
    dummyNode.next = head;
    
    LinkList fast = head->next;
    LinkList slow = head;
    LinkList pre = &dummyNode;
    
    while ( fast )
    {
        while ( fast && fast->val == slow->val )
        {
            fast = fast->next;
        }
        
        if ( slow->next != fast )
        {
            pre->next = fast; // delete the duplicates
            slow = fast;
        }
        else 
        {
            pre = slow;
            slow = fast;
        } 
        
        if ( fast )
        {
            fast = fast->next;
        }    
    }
    
    return dummyNode.next;
}
```