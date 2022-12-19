
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) return head;
        
        // 设置隐藏哑节点
        ListNode first = new ListNode(-1);
        first.next = head;
        
        // 计算长度
        int n = 0;
        while(head != null) {++n; head = head.next;}
        
        // 归并排序 
        for(int node = 1; node < n; node <<= 1){
            ListNode cur = first.next;
            ListNode tail = first;
            
            while(cur != null){
                // 断链
                ListNode l = cur;
                ListNode r = split(l, node);
                cur = split(r, node);
                
                // 归并挂链
                tail.next = merge(l, r);
                
                // 尾节点下一个元素设置为空
                while(tail.next != null) tail = tail.next;
            }
            
        }
        return first.next;
    }
    
    public ListNode split(ListNode head, int step){
        if(step <= 0) return head;
        
        // step--是不行的
        ListNode first = head;
        while(--step > 0 && first != null){
            first = first.next;
        }
        
        if(first == null) return null;
        
        ListNode next = first.next;
        first.next = null;
        return next;
    }
    
    public ListNode merge(ListNode l, ListNode r){
        ListNode first = new ListNode(-1);
        ListNode dummy = first;
        
        while(l != null && r != null) {
            if(l.val < r.val){
                first.next = l;
                first = l;
                l = l.next;
            }else{
                first.next = r;
                first = r;
                r = r.next;
            }
        }
        first.next = l == null ? r : l;
        return dummy.next;
    }
}
```