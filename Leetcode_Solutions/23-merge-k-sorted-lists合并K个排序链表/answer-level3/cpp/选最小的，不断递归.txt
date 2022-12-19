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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ret = NULL;
        int min = INT_MAX;
        int index = -1;
        
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL && lists[i]->val < min) {
                index = i;
                min = lists[i]->val;
            }
        }
        
        if (index >= 0) {
            ret = lists[index];
            lists[index] = ret->next;
            ret->next = mergeKLists(lists);
        }
        
        return ret;
    }
};
```