```
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length==0){
            return null;
        }
        if (lists.length == 1) {
            return lists[0];
        }
        ListNode[] left = Arrays.copyOfRange(lists, 0, lists.length / 2);
        ListNode[] right = Arrays.copyOfRange(lists, lists.length / 2, lists.length);
        ListNode templeft = mergeKLists(left);
        ListNode tempright = mergeKLists(right);
        return mergetList(templeft, tempright);

    }

    private ListNode mergetList(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        if (l2 == null) {
            return l1;
        }

        if (l1.val < l2.val) {
            l1.next = mergetList(l1.next, l2);
            return l1;
        } else {
            l2.next = mergetList(l1, l2.next);
            return l2;
        }
    }
}
```
