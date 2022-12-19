通过数组存储每个节点，删除位置如果删除头节点或者链表的长度为1需要进行额外判断
```Java
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        List<ListNode> list = new ArrayList<>();
        while (head != null) {
            list.add(head);
            head = head.next;
        }
        if ((list.size() - n - 1) < 0){
            if(list.size() > 1){
                return list.get(1);
            } else {
                return null;
            }
        }
        list.get(list.size() - n - 1).next = (list.size() - n + 1 > (list.size() - 1)) ? null:list.get((list.size() - n + 1));
        return list.get(0);
    }
}
```
