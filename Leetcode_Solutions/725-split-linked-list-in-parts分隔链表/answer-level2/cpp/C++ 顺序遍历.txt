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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int s = 0;
        auto node = root;
        while (node != NULL) {
            node = node->next;
            ++s;
        }
        vector<int> nums(k, s / k);
        int l = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < (s - l); ++i) {
            ++nums[i];
        }
        vector<ListNode*> res;
        node = root;
        for (auto n : nums) {
            res.push_back(node);
            ListNode* end = NULL;
            for (int i = 0; i < n; ++i) {
                end = node;
                node = node->next;
            }
            if (end != NULL) end->next = NULL;
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/9f9ae93e8c1b0a6eb40fa30c3cc47738e8ef41f6fe0a8d75f877c9184022ad56-image.png)

