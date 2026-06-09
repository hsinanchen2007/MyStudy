
通过计算两链长度，减去长度差，
让两链一起next往前走，找到共同的交点
```

public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        ListNode p1 = headA;
        ListNode p2 = headB;
        int a = 0;
        int b = 0;
        int c = 0;
        ListNode pp1;
        ListNode pp2;

        // 先求出两条链的长度a
        while(p1!=null){
            p1 = p1.next;
            a++;
        }

        // 先求出两条链的长度b
        while(p2!=null){
            p2 = p2.next;
            b++;
        }

        // 两种情况：两链等长；不等长
        if(a != b){
            // 不等长
            c = (a-b)>0?(a-b):(b-a);
            pp1 = (a-b)>0?headA:headB;
            pp2 = (a-b)>0?headB:headA;

            // 长链先走c步，循环n
            for(int i = 0;i<c;i++){
                pp1 = pp1.next;
            }
        }else{
            // 等长
            pp1 = headA;
            pp2 = headB;
        }

        // 一起走
        while(true){
            if(pp1 == pp2){
                return pp1;
            }
            pp1 = pp1.next;
            pp2 = pp2.next;
        }

        
        
    }
}
```
