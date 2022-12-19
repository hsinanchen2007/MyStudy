### 解题思路
判断是否重复，使用HashSet标记当前节点值是否出现过。
HashSet的add方法会返回boolean值表示是否添加成功，利用返回值就不必再用contains方法，可以节省时间。
### 代码

```java
/**
 * 8ms版本
 */
class Solution {
    public ListNode removeDuplicateNodes(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode currentNode = head;
        HashSet<Integer> intSet = new HashSet<>();
        intSet.add(head.val);
        while (null != currentNode.next) {
            if (intSet.contains(currentNode.next.val)) {
                currentNode.next = currentNode.next.next;
            } else {
                intSet.add(currentNode.next.val);
                currentNode = currentNode.next;
            }
        }
        return head;
    }
}
```

```java
/**
 * 优化后 5ms版本
 */
class Solution {
    public ListNode removeDuplicateNodes(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode currentNode = head;
        HashSet<Integer> intSet = new HashSet<>();
        intSet.add(head.val);
        while (null != currentNode.next) {
            if (intSet.add(currentNode.next.val)) {
                currentNode = currentNode.next;
            } else {
                currentNode.next = currentNode.next.next;
            }
        }
        return head;
    }
}
```
