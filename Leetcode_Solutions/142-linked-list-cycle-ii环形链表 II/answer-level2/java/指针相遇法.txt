


思路：
1.先新建两个指针分别指向头部
2.慢指针p1每次走一步，快指针p2每次走两步
3.如果存在环，那么快指针跟慢指针一定会相遇在环的某个点P
4.假设起点到入环点的距离为D，入环点到第一次相遇点的距离为S1，环的剩余长度为S2，
  因为环走一圈会回到原点
5.这样可计算相遇时  P1走的长度为 D + S1,P2走的长度为 D + S1 + n(S1 + S2)
6.由2可知P2走的距离是P1的两倍，所以得到 2（D + S1） =  D + S1 + n(S1 + S2)
  化简可得D = (n - 1)(S1 + S2) + S2;从移动距离来讲，S1+S2=0,所以D = S2;
7.所以当p1和p2相遇后，将p2放回原点，p1和p2按1步走，再次相遇的点就是入环点
  
```
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null || head.next == null){
            return null;
        }
        if(head.next.next == head) 
            return head; 
        
        ListNode p1 = head;
        ListNode p2 = head;
        
        //是否相遇
        boolean meet = false;
        
        while( p2.next != null && p2.next.next != null){
            if(!meet){
                 p1= p1.next;
                 p2 = p2.next.next;
            }else{
                 p1= p1.next;
                 p2 = p2.next;
            }
           
            //第一次相遇,要把快指针p2放回起点
            if(p1 == p2 && !meet ){
                meet = true;
                p2 = head;
            }
            //第二次相遇
            else if(p1 == p2 && meet){
                return p1;
            }
            
        }
        return null;
        
    }
}
```