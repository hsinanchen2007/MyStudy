执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.43%
的用户
内存消耗 :
36.7 MB
, 在所有 Java 提交中击败了
96.14%
的用户
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head==null||head.next==null||k==1)return head;
      
        ListNode res=new ListNode(0);
        res.next = head;
        ListNode h = head;
        ListNode cur = res;
        ListNode last = head;
        ListNode lasthead = res;
        ListNode kn = head;
        boolean gtk = false;
        int ki=1;
        while((kn = kn.next)!=null){
            ki++;
            if(ki==k){
                gtk=true;
                break;
            }
        }
        if(!gtk)return head;
        //System.out.println(ki+"_"+kn.val);
        int j=0;
        while((kn = kn.next)!=null){
            ki++;
            j++;
             cur = cur.next;
            if(ki%k==1){
             //    System.out.println("ddddddd"+ki+cur.val);
                last = cur;
                h = cur;
            }else{
             //    System.out.println("eeeedd"+ki+cur.val);
                last.next = cur.next;
                cur.next = h;
                h = cur;
                cur = last;
               
            }
           
             if(ki%k==0){
                lasthead.next = h;
                lasthead = cur;
            }
           // pri(h);
        }
        
       // if(j==0)j++;
        int v = j%k;
        while(v<k){
            v++;
             cur = cur.next;
            if(v%k==1){
               // System.out.println("dddd"+v+cur.val);
                last = cur;
                h = cur;
            }else{
               //  System.out.println("cccc"+v+cur.val);
                //  System.out.println("wwwww"+v+cur.val);
                last.next = cur.next;
                cur.next = h;
                h = cur;
                cur = last;

            }
            if(v%k==0){
                 lasthead.next = h;
                 lasthead = cur;
            }
            
        }
        return res.next;
    }
    private void pri(ListNode res){
        System.out.println("---");
        System.out.print(res.val);
        while((res=res.next)!=null)
             System.out.print(res.val);
        System.out.println("---");
        
    }
}
```
