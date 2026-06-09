### 解题思路
l1和l2两个指针在两个链表间交替往前走，smaller和larger两个指针保存当前最小最大。head保存结果链表的头指针。

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        ListNode *head = nullptr;
        while(l1 != nullptr && l2 != nullptr)
        {
            auto smaller = l1->val >= l2->val? l2 : l1;
            auto larger = l1->val >= l2->val? l1 : l2;
            if(head == nullptr) head = smaller;
            while(smaller->next != nullptr && smaller->next->val <= larger->val) 
                smaller = smaller->next;

            l1 = smaller->next;
            smaller->next = l2 = larger;
        }
        return head;
    }
};
```