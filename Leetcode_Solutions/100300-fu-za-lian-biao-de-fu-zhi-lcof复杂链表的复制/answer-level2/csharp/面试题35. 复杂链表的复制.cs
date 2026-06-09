### 解题思路
三次遍历：
1：将每个节点的复制节点紧跟着插入在原节点下一个位置
2：复制随机引用
3：分拆两个链表

### 代码

```java
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/
class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) return head;
        var currentNode = head;
        while (currentNode != null)
        {
            // 将每个节点的复制节点插入到此节点后面
            var copyNode = new Node(currentNode.val, currentNode.next, null);
            currentNode.next = copyNode;
            currentNode = copyNode.next;
        }

        var dummy = new Node(0, null, null);
        var dummyTail = dummy;
        currentNode = head;
        while (currentNode != null)
        {
            if (currentNode.random != null)
            {
                // 复制随机引用
                currentNode.next.random = currentNode.random.next;
            }
            currentNode = currentNode.next.next;
        }

        currentNode = head;
        while (currentNode != null)
        {
            // 分拆链表
            dummyTail.next = currentNode.next;
            currentNode.next = currentNode.next.next;
            currentNode = currentNode.next;
            dummyTail = dummyTail.next;
        }
        dummyTail.next = null;
        return dummy.next;
    }
}
```