```
class Solution {

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode headPre = new ListNode(0);
        headPre.next = head;
        ListNode tmp = headPre;
        
        
        int checked = 0;
        ListNode cheNode = head;
        while (cheNode!=null) {
            checked++;
            cheNode = cheNode.next;
        }
        
        
        ListNode m1;
        ListNode m2;
        int count = 0;
        int count1 = 0;
        ListNode tmp1;
        while (checked>=k) {
            m1 = tmp.next;
            m2 = tmp.next;
            // tmp1 = m1;
            count = 0;
            while (count++ < k) {
                m2 = m2.next;
            }
            // count1 = count;
            for (int i = 0; i < k; ++i) {
                tmp1 = m1;
                count1 = k-1;
                while (count1-- > i) {
                    tmp1 = tmp1.next;
                }
                tmp.next = tmp1;   
                tmp = tmp.next;
            }
            tmp.next = m2;
            
            cheNode = tmp.next;
            checked = 0;
            while (cheNode!=null) {
                checked++;
                cheNode = cheNode.next;
            }
        }
        
        return headPre.next;
    }
}
```
