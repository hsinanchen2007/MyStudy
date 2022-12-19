
public void deleteNode(ListNode node) 题目只给了一个参数

思想

首先要明白题目的意思,题目的意思,这个题目是阅读理解,题目的意思是删除链表中的节点,删除节点,意思是这个节点可以不要了

* @param node 题目给的是删除节点，那说明这个节点可以舍弃了，我们把下一个节点的值拷贝给当前要删除的节点，再删除下一个节点。

* 大致过程如下（删除3）：

* 1->2->3->4->5

* 1->2->4->4->5

* 1->2->4->5 */
```
public void deleteNode(ListNode node) {
    if (node == null) {
        return;
    }
    node.val = node.next.val;
    node.next = node.next.next;
}
```
