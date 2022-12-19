```
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Map <ListNode, Integer> map = new HashMap<>();
        while(headA!=null){
            map.put(headA,1);
            headA=headA.next;
        }
        while(headB!=null){
            if(map.containsKey(headB)){
                return headB;
            }
            headB=headB.next;
        }
        return null;
    }

}
```
