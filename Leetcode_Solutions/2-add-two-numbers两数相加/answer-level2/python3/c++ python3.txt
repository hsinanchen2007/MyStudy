

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
        ListNode head(0), *p = &head;
        int carry = 0;
        while(l1 || l2 || carry){
            int val = carry;
            if(l1){
                val += l1->val;
                l1 = l1->next;
            }
            if(l2){
                val += l2->val;
                l2 = l2->next;
            }
            carry = val / 10;
            p->next = new ListNode(val % 10);
            p = p->next;
        }
        return head.next;
    }
};
```

```python3
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        root = node = ListNode(0)
        while l1 or l2 or carry:
            val = carry
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            carry, val = divmod(val, 10) 
            node.next = ListNode(val)
            node = node.next
        return root.next
```