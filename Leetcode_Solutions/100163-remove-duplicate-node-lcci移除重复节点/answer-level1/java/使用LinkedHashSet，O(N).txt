### 解题思路
因为要求移除重复节点，我们便可利用Set interface来解题。因为输出是依据输入的，所以不能使用TreeSet，这会排序的，要求输入和输出有着相同顺序，只能使用LinkedHashSet了，LinkedHashSet的add以及iterator的每一次操作只耗常数时间，由此可知时间复杂度为O(N), N为输入链表的长度。

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
    public ListNode removeDuplicateNodes(ListNode head) {
        if(head == null)
            return head;
        LinkedHashSet<Integer> set = new LinkedHashSet();
        while(head != null){
            set.add(head.val);
            head = head.next;
        }
        Iterator<Integer> iterator = set.iterator();
        ListNode newHead = new ListNode(iterator.next());
        ListNode node = newHead;
        while(iterator.hasNext()){
            node.next = new ListNode(iterator.next());
            node = node.next;
        }
        return newHead;
    }
}
```