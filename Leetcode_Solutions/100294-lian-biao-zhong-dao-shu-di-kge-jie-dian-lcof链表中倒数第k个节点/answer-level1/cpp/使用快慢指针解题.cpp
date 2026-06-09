### 解题思路


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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        //运用快慢指针，快指针提前走K个单位
        ListNode* fast=head;
        ListNode* slow =head;
        while(k--)//快指针提前走k个单位
        {
            if(fast->next!=nullptr)//防止k的值等于指针所指的个数
            fast=fast->next;
            else return head;
        }
        while(fast!=nullptr&&fast->next!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        //fast走到最后一个指针，slow还需要再走一个单位
        slow=slow->next;
        return slow;
    }
};
```