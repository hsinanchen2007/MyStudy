```
   /**
     * 两个链表在交叉后走过的长度肯定是一样
     * 1、先求出两个链表的长度
     * 2、快慢指针
     * 3、找到指针的交叉点
     * @param headA
     * @param headB
     * @return
     */
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA==null||headB==null){
            return null;
        }
        ListNode pointA=new ListNode(0);
        pointA.next=headA;
        ListNode pointB=new ListNode(0);
        pointB.next=headB;
        int lengthA=0;
        while (pointA.next!=null){
            lengthA++;
            pointA=pointA.next;

        }
        int lengthB=0;
        while (pointB.next!=null){
            lengthB++;
            pointB=pointB.next;

        }

        int step=Math.abs(lengthA-lengthB);

        if(lengthA>lengthB){
            while (step>0){
                headA=headA.next;
                step--;
            }
        }else {
            while (step > 0) {
                headB = headB.next;
                step--;
            }
        }

        while (headA!=null){
            if(headA==headB){
                return headA;
            }
            headA=headA.next;
            headB=headB.next;
        }
        return null;

    }

```
