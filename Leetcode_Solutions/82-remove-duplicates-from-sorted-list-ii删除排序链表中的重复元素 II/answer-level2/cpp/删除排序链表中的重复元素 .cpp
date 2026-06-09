### 解题思路

1. 把准循环不变式，写代码的时候时刻思考：循环如何继续下去？
2. 引入哑节点，可以大幅降低程序的复杂度；1，1，2，2，3；如果是常规思路的话，把将来要删除的节点1作为pre， 程序处理起来会极其复杂

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
    ListNode* deleteDuplicates(ListNode* head) {
        //利用哑节点，大幅减少程序复杂度
        ListNode* dummy = new ListNode(-1); 
        dummy->next = head;
        ListNode* cur = head;
        ListNode* pre = dummy;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) { //相等
                while (cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                pre->next = cur->next;
                cur = cur->next;
            }
            else { //不等
                pre = cur;
                cur = cur->next;
            }
        }

        return dummy->next; 
    }
};
```