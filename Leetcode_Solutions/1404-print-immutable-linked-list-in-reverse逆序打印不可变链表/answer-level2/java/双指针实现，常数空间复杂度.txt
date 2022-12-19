这道题其实利用了“找出倒数第n个节点”这道题的思路，每次让n加一，直到n等于链表长度为止。

我们引入 `fast_begin` 变量，开始时指向 `head` 的下一个节点，作为每次迭代时快指针 `fast` 开始的位置，慢指针 `slow` 每次都指向 `head` 节点。让 `fast` 和 `slow` 每次各走一步，当 `fast` 走到链表尽头时，慢指针 `slow` 指向的节点就是我们要找的节点。打印 `slow` 之后，即可让 `fast_begin` 前进一步，然后重复以上步骤，直到 `fast_begin` 也走到尽头。

迭代完毕时会发现我们漏掉了 `head` ，打印之即可。

代码如下：
```c++ []
class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (head == nullptr)
            return;
        ImmutableListNode* fast_begin = head->getNext();
        while (fast_begin != nullptr) {
            ImmutableListNode* slow = head;
            ImmutableListNode* fast = fast_begin;
            while (fast != nullptr) {
                slow = slow->getNext();
                fast = fast->getNext();
            }
            slow->printValue();
            fast_begin = fast_begin->getNext();
        }
        head->printValue();
    }
};
```
```java []
class Solution {
    public void printLinkedListInReverse(ImmutableListNode head) {
        if (head == null)
            return;
        ImmutableListNode fastBegin = head.getNext();
        while (fastBegin != null) {
            ImmutableListNode slow = head;
            ImmutableListNode fast = fastBegin;
            while (fast != null) {
                slow = slow.getNext();
                fast = fast.getNext();
            }
            slow.printValue();
            fastBegin = fastBegin.getNext();
        }
        head.printValue();
    }
}
```
```python []
class Solution:
    def printLinkedListInReverse(self, head: 'ImmutableListNode') -> None:
        if head is None:
            return
        fast_begin = head.getNext();
        while fast_begin is not None:
            slow = head
            fast = fast_begin
            while fast is not None:
                slow = slow.getNext()
                fast = fast.getNext()
            slow.printValue()
            fast_begin = fast_begin.getNext()
        head.printValue()
```
```javascript []
var printLinkedListInReverse = function(head) {
    if (head === null)
        return;
    let fastBegin = head.getNext();
    while (fastBegin !== null) {
        let slow = head;
        let fast = fastBegin;
        while (fast !== null) {
            slow = slow.getNext();
            fast = fast.getNext();
        }
        slow.printValue();
        fastBegin = fastBegin.getNext();
    }
    head.printValue();
};
```

这个方法只额外引入了三个指针（引用）变量，未使用额外的数据结构，也未使用递归，所以空间复杂度为 O(1)，但是每打印完一个节点，都需要重新遍历一遍链表，所以时间复杂度为 O(n^2)，典型的时间换空间思路。

