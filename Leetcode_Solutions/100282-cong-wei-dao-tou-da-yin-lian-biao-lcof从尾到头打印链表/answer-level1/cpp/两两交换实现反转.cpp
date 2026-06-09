class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> nums;
        while(head){
            nums.push_back(head->val);
            head = head->next;
        }
        int n = nums.size() / 2;
        int j = nums.size() - 1;
        for(int i = 0; i < n; ++i){
            swap(nums[i], nums[j--]);
        }
        return nums;
    }
};