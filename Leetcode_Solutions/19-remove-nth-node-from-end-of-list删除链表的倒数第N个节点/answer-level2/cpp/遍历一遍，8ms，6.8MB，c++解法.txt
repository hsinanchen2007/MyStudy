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
 #include <vector>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur = head;
        int len(0);
        vector<ListNode *> ptr_arr;
        while (cur != nullptr) {
            ptr_arr.push_back(cur);
            len++;
            cur = cur->next;
        }
        if (len - n - 1 >= 0) {
            ptr_arr[len - n - 1]->next = (len > (len - n + 1) ? ptr_arr[len - n + 1] : nullptr);
        } else {
            ptr_arr[0] = (ptr_arr.size() > 1 ? ptr_arr[len - n + 1] : nullptr);
        }
        return ptr_arr[0];
    }
};
```