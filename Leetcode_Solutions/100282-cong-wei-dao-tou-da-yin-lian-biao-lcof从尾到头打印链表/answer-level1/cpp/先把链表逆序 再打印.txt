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
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode* pre;
        ListNode* cur;
        pre=head;
        cur=NULL;

        while(pre!=NULL){
            ListNode* t=pre->next;
            pre->next=cur;
            cur=pre;
            pre=t;
        }

        while(cur!=NULL){
            res.push_back(cur->val);
            cur=cur->next;
        }
        return res;
    }
};