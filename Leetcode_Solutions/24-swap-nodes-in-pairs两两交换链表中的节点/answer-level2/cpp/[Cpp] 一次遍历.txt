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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* pre = head;
        ListNode* now = head->next;
        ListNode* res = head->next;
        while (true) {
            ListNode* tmp = now->next;
            now->next = pre;
            // 先将当前的结点的下一个结点置为后面的第一个结点
            pre->next = tmp;
            if (!tmp || !tmp->next) break;
            // 如果还有下次两个结点交换，当前的下一个结点应为后面的第二个结点
            pre->next = tmp->next;
            pre = tmp;
            now = pre->next;
        }
        return res;
    }
};
```