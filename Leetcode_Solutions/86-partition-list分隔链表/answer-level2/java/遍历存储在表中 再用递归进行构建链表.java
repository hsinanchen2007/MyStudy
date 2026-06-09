### 解题思路
先遍历给定链表 
小于x则存储在smallNode列表中 
大于等于则存储在largeNode列表中

遍历结束后将largeNode列表 加入到smallNode中
此时列表的顺序即为输出链表的顺序

再根据顺序用递归构建结果
### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        List<ListNode> smallNode = new ArrayList<>();
        List<ListNode> largeNode = new ArrayList<>();
        while (head != null){
            if (head.val < x){
                smallNode.add(new ListNode(head.val));
            }else {
                largeNode.add(new ListNode(head.val));
            }
            head = head.next;
        }
        smallNode.addAll(largeNode);
        return buildNode(smallNode, 0, smallNode.size());
    }

    private ListNode buildNode(List<ListNode> list, int index, int size){
        if (index >= size){
            return null;
        }
        ListNode node = new ListNode(list.get(index).val);
        node.next = buildNode(list, index + 1, size);
        return node;
    }
}
```