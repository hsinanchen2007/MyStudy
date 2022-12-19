### 解题思路
删除结点就是两句话的事。
嫁祸于人，要求删除的是node，实际上删除的却是node.next。

### 代码

```java
class Solution {
    public void deleteNode(ListNode node) {
        node.val = node.next.val;
        node.next = node.next.next;
    }
}
```