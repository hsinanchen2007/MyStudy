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
        if(head == NULL || head->next == NULL || head->next->next == NULL) return ;
        ListNode* pre = head;
        ListNode* cur = head;
        while(pre->next->next != NULL){
            pre = pre->next;
        }
        pre->next->next = cur->next;
        cur->next = pre->next;
        pre->next = NULL;
        reorderList(cur->next->next);
        // return head;
    }
};
```