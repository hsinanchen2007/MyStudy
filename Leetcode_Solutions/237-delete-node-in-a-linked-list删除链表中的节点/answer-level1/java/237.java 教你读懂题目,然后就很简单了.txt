### 解法

```java
public void deleteNode(ListNode node) {
        while(node.next.next != null){
            node.val = node.next.val;
            node = node.next;
        }
        node.val = node.next.val;
        node.next = null;
    }
```

思路分析：

* 这个题的难点在于读题目，给定的输入不是`head`而是要删除的值的结点。没有头结点，就不能通过找到要删除的结点的上一个结点，通过改变连接来删除指定结点。
* 再看一下奇怪的说明。给定结点不是末尾结点，链表包含至少两个结点。如果通过值的覆盖，来完成删除值。那么当前的结点需要用下一个结点的值来覆盖，所以题目说给定结点不是末尾结点。最终是要删除一个值，意味着会减少一个结点，因为覆盖需要一直进行，所以删除的结点只能是尾结点。
* 覆盖结点值是一个简单的迭代`node.val = node.next.val; node = node.next; `。关键在于什么时候停止？删除尾结点，就需要在尾结点的前一个结点停止`while(node.next.next != null)`，然后用尾结点的值覆盖其前一个节点，最后前一个结点的`node.next = null`
* 时间复杂度为$O(n)$，空间复杂度为$O(1)$。

运行结果：

* 执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
* 内存消耗 :38.5 MB, 在所有 Java 提交中击败了5.07%的用户

更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖