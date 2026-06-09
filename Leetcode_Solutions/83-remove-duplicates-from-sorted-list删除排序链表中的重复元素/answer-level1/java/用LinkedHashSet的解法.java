一开始因为看错题目了，没有看清是有序的，以为可能会出现重复字符不是紧挨着的情况，因此想到了用java自带的LinkedHashSet来做。
代码如下：
```java
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        // 题目中其实已经是排好序的链表了，如果没有排序的链表，可能出现重复字符不是紧挨着的，这样的话可以用LinkedHashSet来去重，
        // 因为LinkedHashSet的插入顺序和查找顺序是一致的
        Set<Integer> set = new LinkedHashSet<>();
        if (head == null) {
            return head;
        }
        while (head != null) {
            set.add(head.val);
            head = head.next;
        }

        // 设置哑节点
        ListNode dummyNode = new ListNode(-1);
        ListNode prev = dummyNode;
        for (Integer node : set) {
            prev.next = new ListNode(node);
            prev = prev.next;
        }

        return dummyNode.next;
    }
}
```