```
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ArrayList<Integer> list = new ArrayList<>();
        for (ListNode p : lists) {
            while (p != null) {
                list.add(p.val);
                p = p.next;
            }
        }
        Collections.sort(list);
        ListNode head = new ListNode(0);
        ListNode p = head;
        for (Integer integer : list) {
            p.next = new ListNode(integer);
            p = p.next;
        }
        return head.next;
    }
}
```
