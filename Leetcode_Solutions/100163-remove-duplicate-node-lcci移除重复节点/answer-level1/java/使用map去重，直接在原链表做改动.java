处理重复问题使用的是HashMap数据类型
首先定义一个用来输出的result节点，然后定义一个用来保存前驱节点的pre
接下来就是遍历链表了
判断这个节点的值出现过没有：
1.如果出现过那么让pre指向head.next，并且pre不用动，因为head被移除了，head.next的pre还是当前的pre
2.如果没出现过那么在map里加上这个节点的值，并且将pre指向head本身
```
 public ListNode removeDuplicateNodes(ListNode head) {
        Map<Integer, Integer> map = new HashMap<>();
        ListNode result = head;
        ListNode pre = null;
        while (head != null) {
            if (map.get(head.val) != null)
                pre.next = head.next;
            else {
                map.put(head.val, 1);
                pre = head;
            }
            head = head.next;
        }
        return result;
    }
```
