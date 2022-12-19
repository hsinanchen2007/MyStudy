```
插头法
class Solution {
    public int[] reversePrint(ListNode head) {
        if (head == null)
            return new int[0] ;
        ListNode dummyNode = new ListNode(-1) ;
        dummyNode.next = head ;
        ListNode curNode = head ;
        ListNode nextNode = curNode.next ;
        int len = 0 ;
        while (curNode != null ) {
            len ++ ;
            nextNode = curNode.next ;

            if (curNode.next != dummyNode.next){
                curNode.next = dummyNode.next ;
                dummyNode.next  = curNode ;
            }else
                curNode.next = null ;

            curNode = nextNode ;
           
        }

        int[] ret = new int[len] ;
        curNode = dummyNode.next ;
        int i = 0 ;
        while (curNode != null && i < len) {
            ret[i++] = curNode.val ;
            curNode = curNode.next ;
        }

        return ret ;
    }
}
```
