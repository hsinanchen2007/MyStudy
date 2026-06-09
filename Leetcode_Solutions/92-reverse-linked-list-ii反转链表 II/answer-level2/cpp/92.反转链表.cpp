### 解题思路
执行时间0ms,优于100%提交;内存占用10MB，优于5.07提交%
将第m至n个节点从原链表中截取出来送入递归程序进行反转，将反转过的链表与原链表中的某些节点进行拼接即可。
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
    ListNode* reverseList(ListNode* head) {
        if (not head or not head->next){
            return head;
        }
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;

    }

public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n){
            return head;
        }
        ListNode* m_node = head;
        ListNode* n_node = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        int i = 1;
        while (i < m){
            prev = m_node;
            m_node = m_node->next;
            i ++;
        }

        n_node = m_node;
        while(i < n){
            n_node = n_node->next;
            i ++;
        }

        next = n_node->next;
        n_node->next = NULL;
        reverseList(m_node);

        if (m != 1){prev->next = n_node;}
        if (next){m_node->next = next;}
        if (m == 1){return n_node;}
        return head;



    }
};
```