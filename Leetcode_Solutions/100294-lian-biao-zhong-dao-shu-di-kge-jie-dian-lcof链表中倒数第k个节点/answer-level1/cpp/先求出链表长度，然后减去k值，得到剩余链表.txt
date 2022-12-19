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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* dummy=head;
        int len=0;
        while(dummy!=NULL){
            len++;
            dummy=dummy->next;
        }
        int i=len-k;
        while(i!=0){
            i--;
            head=head->next;

        }
        return head;

    }
};