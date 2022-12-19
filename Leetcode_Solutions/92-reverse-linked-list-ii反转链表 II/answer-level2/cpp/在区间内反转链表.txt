### 解题思路
此处撰写解题思路
1. 定反转的段的起点和终点。
2. 反转完片段之后，需要把两端连接到被反转后的链表片段中
3. 边界处理：(1)只有一个元素 (2) 起点和终点相同，即为不翻转，直接输出  (3) m=1的时候，做完翻转之后，链表的head 已经改变。新的head是n的位置

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
        auto* m_node = head;
        auto* n_node = head;

        if (m==n)
            return head;

        ListNode* m_prev = nullptr;
        
        for (int i=1; i<m; ++i) {
            m_prev = m_node;
            m_node = m_node->next;
        }

        auto* n_next = n_node->next;
        for (int i=1; i<n; ++i) {
            n_node = n_next;
            n_next = n_next->next;
        }

        auto* prev = m_prev;
        auto* curr = m_node;

        while (curr != n_next) {
            auto* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;

        }

        if (m_prev != nullptr)
            m_prev->next = n_node;


        m_node->next = n_next;

        return m!=1? head : n_node;
    }
};
```