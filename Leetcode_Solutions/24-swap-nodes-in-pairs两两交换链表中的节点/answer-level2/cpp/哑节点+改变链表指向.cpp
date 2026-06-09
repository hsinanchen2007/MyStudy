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
    ListNode* swapPairs(ListNode* head) {
        if(!head)return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        while(pre->next && pre->next->next)
        {
            ListNode *first = pre->next;
            ListNode *second = pre->next->next;
            //交换first和second，画图理解
            pre->next = second;
            first->next = second->next;
            second->next = first;
            pre = first;  //改变pre的指向；
        }
        return dummy->next;
    }
};
```