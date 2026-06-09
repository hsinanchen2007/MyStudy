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
    bool hasCycle(ListNode *head) {
        if (head==NULL || head->next==NULL) return false;
        ListNode *node = head;
        while (node!=NULL && node->next!=NULL && head!=NULL)
        {
            head = head->next;
            node = node->next->next;
            if (head == node) return true;
        }
        return false;
    }
};
```