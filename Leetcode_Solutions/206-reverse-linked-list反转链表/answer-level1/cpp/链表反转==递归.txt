### 解题思路
  递归思想，参考大佬们的做法，加了点自己的理解。

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
        /* 递归算法 */

        if(head == NULL || head->next == NULL) // 递归终止条件
            return head; 

        // 若不满足递归终止条件，则执行下面程序
        ListNode* Reverse_Node = reverseList(head->next);
        head->next->next = head; // 当前结点指向前一个结点
        head->next = NULL; // 当回退到第一个结点时，指向NULL

        return Reverse_Node;
    }            
};
```