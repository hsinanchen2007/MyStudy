```
class Solution {
    public ListNode partition(ListNode head, int x) {
        List<ListNode> big, small;
        ListNode cursor, smallHead, smallTail, bigHead, bigTail;
        int i;
        
        if(head == null)
            return head;
        big = new ArrayList<>();
        small = new ArrayList<>();
        cursor = head;
        while(cursor != null){
            if(cursor.val < x)
                small.add(cursor);
            else
                big.add(cursor);
            cursor = cursor.next;
        }
        if(small.isEmpty() || big.isEmpty())
            return head;
        smallHead = small.get(0);
        smallTail = smallHead;
        for(i = 1; i < small.size(); i++){
            smallTail.next = small.get(i);
            smallTail = smallTail.next;
        }
        bigHead = big.get(0);
        bigTail = bigHead;
        for(i = 1; i < big.size(); i++){
            bigTail.next = big.get(i);
            bigTail = bigTail.next;
        }
        smallTail.next = bigHead;
        bigTail.next = null;
        return smallHead;
    }
}
```
