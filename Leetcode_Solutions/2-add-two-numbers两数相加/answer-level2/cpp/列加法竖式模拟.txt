* 使用中间变量t记录
```c++
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
    ListNode* add(ListNode *pre, int x) {
        ListNode *ne = new ListNode;
        ne->val = x;
        pre->next = ne;
        pre = ne;
        return pre;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int t = 0;
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode *pre = new ListNode;
        ListNode *head = pre;
        while(p || q) {
            if(p) t += p->val, p = p->next; 
            if(q) t += q->val, q = q->next;
            pre = add(pre, t % 10);
            t /= 10;
        }
        if(t) add(pre, 1);
        return head->next;
    }
};
```