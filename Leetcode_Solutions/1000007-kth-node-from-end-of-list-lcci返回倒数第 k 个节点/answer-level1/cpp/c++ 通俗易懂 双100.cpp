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
    int kthToLast(ListNode* head, int k) {
        list<int> a;
        a.push_back(head->val);
        while(head->next!=NULL)
        {
            head=head->next;
            a.push_back(head->val);      
        }
        for(int i=0;i<k-1;i++)
        {
           a.pop_back();
        }
        return a.back();
    }
};