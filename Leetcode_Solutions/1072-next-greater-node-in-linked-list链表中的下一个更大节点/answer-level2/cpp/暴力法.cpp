### 解题思路
暴力解法，跟移除相同元素一样，时间复杂度O(n*n)

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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        ListNode* cur = head;

        while (cur)
        {
            ListNode* next = cur->next;
            while (next)
            {
                if (next->val > cur->val)
                {
                    v.push_back(next->val);
                    break;
                }
                next = next->next;
            }
            
            if(next == nullptr)
            {
                v.push_back(0);
            }

            cur = cur->next;
        }
        return v;
    }
};
```