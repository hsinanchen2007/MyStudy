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
    void reorderList(ListNode* head) {
        // 先用暴力的方式来一把
        ListNode *temp_head = head;
        vector<ListNode *> v;

        if (head == NULL) return ;

        while (temp_head) {
            v.push_back(temp_head);
            temp_head = temp_head->next;
        }

        int n = v.size();
        for (int i = 0; i < v.size() && i <= n - i - 1; i++) {
            if (i != n - i - 1) {
                v[n - i - 1]->next = v[i + 1];
                v[i]->next = v[n - i - 1];
            } else {
                v[i]->next = NULL;  
            }
        }

        if (n % 2 == 0) {
            v[n/2]->next = NULL;
        }
    }
};
```