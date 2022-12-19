### 解题思路
超越89和100，思路清晰易懂
![1585115340(1).jpg](https://pic.leetcode-cn.com/9f719352d5c3ac772dfe062f15b05c74f4ecc39788b1f9d462ace8fdaac6f847-1585115340\(1\).jpg)

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
    ListNode* deleteNode(ListNode* head, int val) {
        //我简直要气死了，同一个代码跑三次，一次5，一次16，一次89
        if(head == NULL)
            return NULL;
        if(head->val == val)    //如果删除的是头节点
            return head->next;
        ListNode *p = head;
        while(p->next)  //比较的是next的val，这样的话才能记住上个节点，方便删除节点
        {
            if(p->next->val == val)
            {
                p->next = p->next->next;
                return head;
            }
            p = p->next;
        }
        return head;
    }
};
```