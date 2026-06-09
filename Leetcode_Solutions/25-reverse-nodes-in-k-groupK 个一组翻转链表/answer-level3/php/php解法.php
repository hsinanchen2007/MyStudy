```
class Solution {

    /**
     * @param ListNode $head
     * @param Integer $k
     * @return ListNode
     */
    function reverseKGroup($head, $k) {
        $dummy = new ListNode(0);
        $dummy->next = $head;
        $pre = $dummy;
        $end = $dummy;
        while($end->next!=null){
            for($i=0;$i<$k && $end!=null;$i++) $end = $end->next;
            if($end==null) break;
            $start = $pre->next;
            $next = $end->next;
            $end->next = null;
            $pre->next = $this->reverse($start);
            $start->next = $next;
            $pre = $start;
            
            $end = $pre;
        }
        return $dummy->next;
    }
    
    function reverse($head){
        $pre = new ListNode(null);
        $curr = $head;
        while($curr!=null){
            $next = $curr->next;
            $curr->next = $pre;
            $pre = $curr;
            $curr = $next;
        }
        return $pre;
    }
}
```
