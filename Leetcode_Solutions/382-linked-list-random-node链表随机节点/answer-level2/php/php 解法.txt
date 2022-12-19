```
class Solution {
    /**
     * @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node.
     * @param ListNode $head
     */
    function __construct($head) {
        $this->head = $head;
    }

    private $head;
  
    /**
     * Returns a random node's value.
     * @return Integer
     */
    function getRandom() {
        $cur = $this->head;
        $n = 1;
        $val = $cur->val;
        $cur = $cur->next;
        while($cur != null){
            $n++;
            if(rand()%$n==0) $val = $cur->val;
            $cur = $cur->next;
        }
        return $val;
    }
}
```
