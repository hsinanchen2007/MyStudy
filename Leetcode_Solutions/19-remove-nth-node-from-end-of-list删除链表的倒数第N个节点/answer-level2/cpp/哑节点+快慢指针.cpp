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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        ListNode *slow = head, *fast = head;
        while(n--)
        {
            fast = fast->next;  //快指针先走n步
        }
        while(fast && slow)
        {
            fast = fast->next;
            slow = slow->next;
            pre = pre->next;
        }
        //此时slow指向的就是倒数第n个节点
        pre->next = slow->next;  //更改pre的指向，将slow脱离开来
        delete slow;
        return dummy->next;
    }
};
```