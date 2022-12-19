```
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode *p = head;
        while (NULL != p)
        {
            nums.push_back(p->val);
            p = p->next;
        }
        sort(nums.begin(), nums.end());
        
        int i = 0;
        p = head;
        while (NULL != p)
        {
            p->val = nums[i++];
            p = p->next;
        }
        return head;

    }
```
