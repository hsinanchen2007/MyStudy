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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> l;
        l[head]++;
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* ans = nullptr;
        while (head != nullptr) {
            head = head->next;
            l[head]++;
            if (l[head] > 1) {
                ans = head;
                break;
            }
        }
        return ans;
    }
};
```