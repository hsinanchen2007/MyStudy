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
    int kthToLast(ListNode* head, int k) {
        if(head==nullptr) return -1;
        ListNode* copyhead = head;
        vector<int> arr;
        while(copyhead!=nullptr)
        {
            arr.push_back(copyhead->val);
            copyhead = copyhead -> next;
        }
        return arr[arr.size()-k];
    }
};
```