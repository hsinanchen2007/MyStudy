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
    bool isPalindrome(ListNode* head) {
        vector<int> res;
        while(head)
        {
            res.push_back(head->val);
            head=head->next;
        }
        vector<int> t(res.rbegin(),res.rend());
        return t==res?true:false;
    }
};
```
