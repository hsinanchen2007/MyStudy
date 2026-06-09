### 解题思路
链表的翻转 + 递归
1. 翻转前k个链表，返回头节点
2. 上一轮翻转后的尾接点 指向 下一轮的头节点

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
        if (!head) 
            return head;

        ListNode *tail = head;
        for(int i=0;i<k;i++)
        {
            if (tail == NULL) // 不足k个节点，返回head
                return head;
            tail = tail->next;
        }

        // 翻转前k个节点，返回头节点， 翻转后head为尾接点
        ListNode* newhead = reverse(head, tail);
        // 上一轮翻转后的尾接点 指向 下一轮的头节点
        head->next = reverseKGroup(tail, k);
    
        return newhead;
    }
    /*链表的翻转, 左闭右开*/
    ListNode* reverse(ListNode* head, ListNode* tail)
    {   
        ListNode *pre=head;
        ListNode *cur = pre->next;
        ListNode *next = NULL;
        while(cur!=tail)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
```