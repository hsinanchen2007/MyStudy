### 解题思路
![捕获.PNG](https://pic.leetcode-cn.com/81834ffdd333132d6b3ff5fa68096fe5abab147b88125e9f1a919c10f5bbabac-%E6%8D%95%E8%8E%B7.PNG)


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k == 1) return head;
        ListNode* p = head, *q; 
        int num = 0, m = 1, n = k;
        while(p) { num++; p = p->next; }
        while(num >= k)
        {
            q = reverseBetween(head, m, n); head = q;
            m += k; n += k;
            num -= k;
        }
        return head;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head || !head->next || m == n) return head;
        ListNode* pre = new ListNode(0), *p = head, *q = head->next, *tmp;
        pre->next = head;
        int i;
        for(i = 0; i < m - 1; i++)
        {
            pre = p; p = p->next; q = q->next;
        }
        for(; i < n - 1; i++)
        {
            tmp = q; q = q->next; tmp->next = p; p = tmp;
        }
        pre->next->next = q;
        pre->next = p;
        return m == 1 ? pre->next : head;
    }
};
```