### 解题思路
新建第三个链表，记录l1，l2之和
（用原链表的其中一个也可以）

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* head = l3;
        int carry = 0;
        while(l1 != NULL || l2 != NULL){
            l3->next = new ListNode(0);
            l3 = l3->next;
            int a1 = 0, a2 = 0;
            if(l1 != NULL ) {a1 = l1->val;l1 = l1->next;}
            if(l2 != NULL ) {a2 = l2->val;l2 = l2->next;}
            l3->val = (a1 + a2 + carry)%10;
            carry = (a1 + a2 + carry)/10;
            
        }
        if(carry){
            l3->next = new ListNode(0);
            l3 = l3->next;
            l3->val = carry;
        }
        return head->next;
    }
};
```