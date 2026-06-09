### 解题思路
没有用环的思想，但是觉得这种方法比较简单

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

struct ListNode* rotateRight(struct ListNode* head, int k){
    if ( head == NULL || k <= 0)
    {
        return head;
    }
    
    LinkList cur = head;
    LinkList rear = head; // new rear
    LinkList new = NULL; // new head
    
    int count = k;
    int length = 0;

    while ( 0 < count )
    {
        if ( NULL == cur->next ) // once k >= length
        {
            length = k - count + 1;
            count = k % length;
            cur = head;    
            
            if ( 0 == count )
            {
                break;
            }
        }
        
        cur = cur->next;
        count--;
    }

    while ( cur->next )
    {
        cur = cur->next;
        rear = rear->next;
    }

    cur->next = head;
    new = rear->next;
    rear->next = NULL;

    return new; 
}
```