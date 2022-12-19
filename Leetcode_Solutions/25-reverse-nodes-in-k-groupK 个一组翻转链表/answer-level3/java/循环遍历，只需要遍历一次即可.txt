```java
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        
        if( k == 0 || k == 1){
            return head;
        }
        
        ListNode p = head;
        int count = 0;
        
        while(p != null){
            count++;
            p = p.next;
        }
        
        p = head;
        ListNode prev = new ListNode(-1);
        prev.next = head;
        
        ListNode cur = head;
        boolean flag = true;
        
        // 计算需要反转多少组
        int cnt = count / k;
        while( cnt != 0){
            cnt--;
            int temp = k;
            
            // 将cur指向的下一个节点转移到prev的下一个节点，一直循环，直到完成一组
            while(temp != 1){
                ListNode tmp = prev.next;
                prev.next = cur.next;
                cur.next = cur.next.next;
                prev.next.next = tmp;
                temp--;  
            }
            
            // 只有第一次会执行，用来记录头结点
            if(flag){
                flag = false;
                head = prev.next;
            }
            
            prev = cur;
            cur = cur.next;
        }
        
        return head;
        
    }
}
```