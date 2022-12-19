### 解题思路
1、递归：先递归地把本节点之后的链表反转，然后相应地改变本节点和本节点的下一个节点的指向关系即可。（参考代码一目了然）
2、迭代：用两个指针head和successor分别标记当前处理的节点和该节点的下一个结点，从头至尾遍历链表，每次处理一个节点，最终可以将整个链表反转。（同样参考代码）
### 代码

**递归**
```scala
object Solution {
    def reverseList(head: ListNode): ListNode = {
        if (head == null || head.next == null)
            return head
        val reversedHead = reverseList(head.next)
        head.next.next = head
        head.next = null
        reversedHead
    }
}
```

**迭代**
```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head)
            return head;
        ListNode *successor = head->next;
        head->next = NULL;
        while (successor) {
            ListNode *tmp = successor->next;
            successor->next = head;
            head = successor;
            successor = tmp;
        }
        return head;
    }
};
```

