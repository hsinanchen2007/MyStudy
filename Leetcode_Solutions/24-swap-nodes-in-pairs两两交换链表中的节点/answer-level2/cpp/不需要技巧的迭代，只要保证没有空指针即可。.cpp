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

ListNode* swapPairs( ListNode* head ) 
{
    ListNode* pre = nullptr;
    ListNode* current = head;
    if ( head == nullptr )
        return nullptr;
    ListNode* next = current->next;
    ListNode* tmp;
    if ( next )
    {
        current->next = next->next;
        pre = next;
        next->next = current;

        current = pre->next;
        if ( current )
        {
            next = current->next;
        }
        head = pre;
    }

    pre = current;
    current = current->next;
    
    if ( next == nullptr )
        return head;

    next = next->next;

    while ( 1 )
    {
        if ( next == nullptr )
            return head;

        current->next = next->next;
        next->next = current;
        pre->next = next;

        if ( current->next == nullptr )
            return head;

        pre = pre->next;
        current = pre->next;
        next = current->next;

        if ( current->next == nullptr )
            return head;

        pre = pre->next;
        current = pre->next;
        next = current->next;
    }

    return head;
}


};