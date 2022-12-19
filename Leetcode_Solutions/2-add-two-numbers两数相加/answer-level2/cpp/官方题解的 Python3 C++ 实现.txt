
## 思路

若两个链表其中之一不为空，就进行下一步，若有一个为空了则其设置val为0。不需要设置多的节点。

这种方法的优势在于省空间。

看了好多c++和python的题解是补齐短的链表，增加值为0的节点，所以做了这个题解，供大家参考，可以打败百分之七八十的人。

## 代码
c++ 代码表示如下：
```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        int sum;
        while (l1 || l2){
            sum = 0;
            if (l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        if (carry > 0) 
            curr->next = new ListNode(carry);
        return dummyHead->next;
    }
};
```
Python 代码表示如下：
```py
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummyHead = ListNode(0)
        curr, carry = dummyHead, 0
        while l1 or l2:
            sum = 0
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next
            sum += carry
            carry = sum // 10
            curr.next = ListNode(sum % 10)
            curr = curr.next
        if carry > 0:
            curr.next = ListNode(1)
        return dummyHead.next;
```