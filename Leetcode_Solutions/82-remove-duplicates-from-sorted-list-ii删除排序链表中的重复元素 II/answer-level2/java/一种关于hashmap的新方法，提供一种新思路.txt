hashmap遍历整个链表，存储每一个节点数值对应的个数，如果等于1，加入链表中，否则一直遍历知道遇到数值仅有一个的节点。
```
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        HashMap<Integer, Integer> hash = new HashMap<>();
        ListNode cur = head;
        while(cur != null) {
            if(!hash.containsKey(cur.val)) hash.put(cur.val, 1);
            else hash.put(cur.val, hash.get(cur.val) + 1);
            cur = cur.next;
        }
        ListNode dummy = new ListNode(0);
        ListNode pre = dummy;
        ListNode cur1 = head;
        while(cur1 != null) {
            while(hash.get(cur1.val) != 1) {
                cur1 = cur1.next;
                if(cur1 == null) break;
            }
            if(cur1 == null) {
                pre.next = null;
                break;
            }
            pre.next = cur1;
            pre = cur1;
            cur1 = cur1.next;
        }
        return dummy.next;
    }
}
```
