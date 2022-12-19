![image.png](https://pic.leetcode-cn.com/70f6520d56c64e27bc25dcf43df71949b38a32955005a96e5d812ffa7ba04db8-image.png)

```
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        int length, n, i;
        ListNode[] reversed;
        ListNode cursor;

        length = getListLength(head);
        if(k > length)
            return head;
        n = length / k;
        reversed = reverseList(head, k);
        head = reversed[0];
        cursor = reversed[1];
        for(i = 1; i < n; i++){
            reversed = reverseList(cursor.next, k);
            cursor.next = reversed[0];
            cursor = reversed[1];
        }
        return head;
    }

    private ListNode[] reverseList(ListNode head, int k){
        ListNode[] answer, reversed;

        answer = new ListNode[2];
        if(k == 1){
            answer[0] = head;
            answer[1] = head;
            return answer;
        }
        reversed = reverseList(head.next, k - 1);
        head.next = reversed[1].next;
        reversed[1].next = head;
        head = reversed[0];
        answer[0] = head;
        answer[1] = reversed[1].next;
        return answer;
    }

    private int getListLength(ListNode head){
        if(head == null)
            return 0;
        return 1 + getListLength(head.next);
    }
}
```
