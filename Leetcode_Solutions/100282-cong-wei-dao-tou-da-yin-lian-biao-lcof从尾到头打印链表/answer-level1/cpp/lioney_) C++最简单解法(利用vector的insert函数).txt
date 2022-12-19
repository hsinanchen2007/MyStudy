```
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while(head) {
            res.insert(res.begin(), head->val);
            head = head->next;
        }
        return res;
    }
};
```
