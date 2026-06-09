### 解题思路
Middle of the Linked List

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
    ListNode* middleNode(ListNode* head) {
        ListNode* n1=head;
        ListNode* n2=head;
        while(n2!=NULL&&n2->next!=NULL)
        {
            n1=n1->next;
            n2=n2->next->next;
        }
        return n1;
    }
};
```