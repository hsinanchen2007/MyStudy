## 思路：

模拟过程

关键要处理 **进位的问题**

一位数和一位数相加，大于 10 时候，除以 10，商为进位数，余数为该位的数。

时间复杂度：$O(n)$

`python` 写的冗长,但是特别容易理解，`java` 和 `c++` 做了简化 。

## 代码：


```Python []
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = ListNode(0)
        p = dummy
        carry_digit = 0
        p1 = l1
        p2 = l2
        while p1 and p2:
            tmp = p1.val + p2.val + carry_digit
            quotient = tmp // 10
            remainder = tmp % 10
            p.next = ListNode(remainder)
            carry_digit = quotient
            p1 = p1.next
            p2 = p2.next
            p = p.next
        while p1:
            tmp = p1.val + carry_digit
            quotient = tmp // 10
            remainder = tmp % 10
            p.next = ListNode(remainder)
            carry_digit = quotient
            p1 = p1.next
            p = p.next
        while p2:
            tmp = p2.val + carry_digit
            quotient = tmp // 10
            remainder = tmp % 10
            p.next = ListNode(remainder)
            carry_digit = quotient
            p2 = p2.next
            p = p.next
        if carry_digit:
            p.next = ListNode(carry_digit)
        
        return dummy.next
```

```C++ []
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
        ListNode dummy(0);
        ListNode *p = &dummy;
        int carry_digit = 0;
        while(l1  || l2  || carry_digit){
            int tmp = (l1 ? l1->val:0) + (l2 ? l2->val:0) + carry_digit;
            carry_digit = tmp / 10;
            int remainder = tmp % 10;
            p->next = new ListNode(remainder);
            p = p->next;
            l1 = l1 ? l1->next:l1;
            l2 = l2 ? l2->next:l2;
        }
        return dummy.next;  
    }
};
```
```Java []
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode p = dummy;
        int carry_digit = 0;
        while (l1 != null || l2 != null || carry_digit != 0){
            int tmp = (l1!=null?l1.val:0)+(l2!=null?l2.val:0)+carry_digit;
            carry_digit = tmp / 10;
            p.next = new ListNode(tmp%10);
            p = p.next;
            l1 = l1 != null ? l1.next:l1;
            l2 = l2 != null ? l2.next:l2;
        }
        return dummy.next;   
    }
}
```

