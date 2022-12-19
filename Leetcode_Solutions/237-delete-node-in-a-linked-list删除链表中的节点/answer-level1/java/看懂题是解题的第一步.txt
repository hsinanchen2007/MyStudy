问题一：输入节点是啥？删除节点是啥？
不知道是不是中文翻译的不太好，given only access to that node.（你将只被给定要求被删除的节点）
输入的节点就是你要删除的节点

问题二：不知道前一个节点，怎么删？
思路就是链表除了指针之外，还以值也是可以操作的，这个节点删不了可以删后一个节点


代码很简单
```java
public class DeleteNode {

    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }

}
```