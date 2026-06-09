```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//设置快慢指针，快的一次走2步，慢的一次走1步，让快的走到头，慢的就是所需值
typedef struct ListNode ListNode;
struct ListNode* middleNode(struct ListNode* head){
    ListNode* slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL)   //必须保证 fast 和 fast->next 不为空
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}
```
