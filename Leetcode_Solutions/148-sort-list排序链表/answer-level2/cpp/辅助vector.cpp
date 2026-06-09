### 解题思路
用到了辅助vector进行排序

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
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return head;
        ListNode* curr = head;
        vector<int> v;
        while (curr) {
            v.push_back(curr->val);
            curr = curr->next;
        }
        sort(v.begin(), v.end());
        int n = v.size();
        curr = head;
        for (int i=0; i<n; i++) {
            curr->val = v[i];
            curr = curr->next;
        }
        return head;
    }
};
```