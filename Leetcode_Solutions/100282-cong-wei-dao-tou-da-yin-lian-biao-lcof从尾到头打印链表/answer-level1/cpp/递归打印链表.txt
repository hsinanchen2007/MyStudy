### 解题思路


### 代码

```cpp
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
    vector<int> res;
    vector<int> reversePrint(ListNode* head) {
        if(!head) return res;
        helper(head,res);
        return res;
    }
    void helper(ListNode* head,vector<int>& res){
        if(head->next)
            helper(head->next,res);
        res.push_back(head->val);
    }
};
```