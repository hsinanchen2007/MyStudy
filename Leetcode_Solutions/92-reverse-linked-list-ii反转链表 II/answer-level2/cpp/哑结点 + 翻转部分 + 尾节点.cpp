### 解题思路
本题与翻转链表思路类似
1. 使用哑结点记录m之前不需要翻转的列表
2. 翻转m~n之间的节点，并记录该翻转链表的rear节点
3. 将哑结点最后节点 + 翻转链表头结点
4. 翻转链表rear结点 + 后续剩余链表首结点

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr) {
            return head;
        }
        if (m == n) {
            return head;
        }
        ListNode dummy(0);
        ListNode* p = &dummy;
        int i = 1;

        while (head && i < m) {
            ++i;
            p->next = head;
            p = head;
            head = head->next;
        }
        if (head == nullptr) {
            return dummy.next;
        }

        ListNode* rear = nullptr;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        head = head->next;
        while (cur && m <= n) {
            if (rear == nullptr) {
                rear = cur;
            }
            cur->next = pre;
            pre = cur;
            cur = head;
            head = head ? head->next : nullptr;
            ++m;
        }
        
        p->next = pre;
        if (cur != nullptr && rear != nullptr) {
            rear->next = cur;
        }
        return dummy.next;
    }
};
```