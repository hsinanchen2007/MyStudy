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
    ListNode* sortList(ListNode* head) {
        vector<int>nums;
        ListNode* p=head;
        while(p!=NULL){
            nums.push_back(p->val);
            p=p->next;
        }
        sort(nums.begin(),nums.end());
        p=head;
        for(int i=0;i<nums.size();i++){
            p->val=nums[i];
            p=p->next;
        }
        return head;
    }
};
```
