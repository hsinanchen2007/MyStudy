```
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* node=head;
        vector<int> nums;
        while(node!=NULL)
        {           
            nums.push_back(node->val);
            node=node->next;
        }
        sort(nums.begin(),nums.end());
        ListNode* code=head;
        for(int i=0;i<nums.size();i++)
        {
            code->val=nums[i];
            code=code->next;
        }
        return head;
    }
};
```
