### 解题思路
此处撰写解题思路

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
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> ans = {head};
        while(ans.back()->next != NULL)
            ans.push_back(ans.back()->next);
        return ans[ans.size() / 2];
    }
};
                                                                                                                                                                                              
```