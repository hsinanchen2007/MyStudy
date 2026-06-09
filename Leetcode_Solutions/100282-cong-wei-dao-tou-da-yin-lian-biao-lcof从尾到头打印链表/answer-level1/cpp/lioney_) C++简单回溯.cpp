```
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(!head) return {};
        vector<int> res;
        helper(head, res);
        return res;
    }
    void helper(ListNode* list, vector<int>& res) {
        if(list->next) {
            helper(list->next, res);
        }
        res.push_back(list->val);
        
    }
};
```
