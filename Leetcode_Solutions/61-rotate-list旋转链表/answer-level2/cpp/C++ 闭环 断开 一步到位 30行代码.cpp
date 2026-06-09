```
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr || k == 0)
            return head;
        int node_n = 1;
        ListNode *pre_head = head;
        ListNode *pre_tail = nullptr;
        ListNode *new_head = nullptr;
        ListNode *new_tail = nullptr;
        
        while(head -> next != nullptr){
            node_n++;
            head = head -> next;
        }
        pre_tail = head;
        
        int new_head_number = k%node_n;
        if(new_head_number == 0)
            return pre_head;
        
        new_tail = pre_head;
        for(int i=0; i < node_n-new_head_number-1 ; i++){
            new_tail = new_tail -> next;
        }
        new_head = new_tail -> next;
        pre_tail -> next = pre_head;
        new_tail -> next = nullptr;
        
        return new_head;
    }
};
```
