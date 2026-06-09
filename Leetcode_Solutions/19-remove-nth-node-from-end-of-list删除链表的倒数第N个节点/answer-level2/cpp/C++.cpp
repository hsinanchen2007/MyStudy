### 解题思路
两个指针
注意删除头的情况，特殊处理下


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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 两个指针的思想
        ListNode* first = head;
        ListNode* second = head;
        ListNode* pre = head;
        
        while (n--) {
            first = first->next;
        }
        while (first != nullptr) {
            pre = second;
            second = second->next;
            first = first->next;
        }
        // second记录了要删除的节点
        // pre　前一个节点
        if (second == head) {
            return head->next;
        } else {
            pre->next = second->next;
        }
        return head;
    }
};
```