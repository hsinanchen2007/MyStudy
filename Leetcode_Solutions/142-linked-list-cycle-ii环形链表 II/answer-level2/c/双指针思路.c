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
typedef struct ListNode Node;
struct ListNode *detectCycle(struct ListNode *head) 
{
    if(head == NULL || head->next == NULL)
        return NULL;
    Node* slow = head;
    Node* fast = head;
    do
    {
        if(fast == NULL || fast->next == NULL)   //双指针，一个走一步，一个走两步，因为fast总是先到头，所以只判fast
            return NULL;
        slow = slow->next;
        fast = fast->next->next;
    }while(slow != fast); 
    
    fast = head;      //此时fast和slow在同一位置，即此链表定为环形链表，但相遇位置不一定是循环的开头，此时让fast置头
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;               //fast和slow同时向前走，此时相遇位置即为循环的开头位置
    }
    return slow;
}
```