### 解题思路
双指针解决链表问题：快慢指针
1.快指针fast每次走两个位置，满指针slow每次走一个位置。
2.若链表存在环状，快慢指针都会在环状处循环，最终fast会追上slow。
3.fast==slow   -》存在环
注意：每次指针的next要判断当前指针是不是nullptr，若是则必定无环。
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
    bool hasCycle(ListNode *head) {
        ListNode *fast,*slow;
        fast=head; slow=head;
        if(fast!=nullptr) fast=fast->next;
        if(slow!=nullptr) slow=slow->next;

        if(fast==nullptr) return false;
        fast=fast->next;

        while(fast&&slow)
        {
            if(fast==slow)
                return true;
            else{
                fast=fast->next;
                if(fast==nullptr) return false;
                fast=fast->next;
                slow=slow->next;
            }
        }
        return false;

    }
};
```