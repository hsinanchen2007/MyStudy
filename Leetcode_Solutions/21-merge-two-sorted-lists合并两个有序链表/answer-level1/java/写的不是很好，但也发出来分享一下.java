class Solution {
    /**
    * 用游标去取两个数组中下一个最大的节点，并把取到的状态为true，可以进行p = p.next操作 
    */
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
           //new一个Head节点;
           ListNode mergeHead = new ListNode(0);
           ListNode p = l1;
           ListNode q = l2;
           //游标;
           ListNode ccur = mergeHead;
           boolean pf = false;
           boolean qf = false;
           while(p != null || q != null){ 
               if(q == null){
                 ccur.next = new ListNode(p.val);
                 ccur = ccur.next;
                 pf = true;
                } else if(p == null){
                 ccur.next = new ListNode(q.val);
                 ccur = ccur.next;
                 qf = true;
               } else {   
                   if(p.val < q.val) {
                       ccur.next = new ListNode(p.val);
                       ccur = ccur.next;
                       pf = true;
                   }else if(q.val < p.val) {
                       ccur.next = new ListNode(q.val);
                       ccur = ccur.next;
                       qf = true;
                   }else if(p.val == q.val){
                       ccur.next = new ListNode(p.val);
                       ccur = ccur.next;
                       pf = true;
                       ccur.next = new ListNode(q.val);
                       ccur = ccur.next;
                       qf = true;
                   } 

               }
               //获取下一个节点;
               if(p != null && pf == true) p = p.next;
               if(q != null && qf == true) q = q.next;
               //恢复状态;
               pf = false;
               qf = false;
           }
           return mergeHead.next;
    }
}