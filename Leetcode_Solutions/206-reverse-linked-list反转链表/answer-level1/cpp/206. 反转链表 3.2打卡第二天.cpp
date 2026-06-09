```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* front = head; head = head->next; ListNode* tmp = head->next;
        front->next = NULL;
        while(head != NULL){
            head->next = front; front = head; head = tmp;
            if(tmp != NULL) tmp = tmp->next;
        }
        return front;
    }
};
```