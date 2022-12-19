```
class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        List<ListNode> list = new ArrayList();
        while(head != null) {
            list.add(head);
            head = head.next;
        }
        return list.get(list.size() - k);
    }
}
```
