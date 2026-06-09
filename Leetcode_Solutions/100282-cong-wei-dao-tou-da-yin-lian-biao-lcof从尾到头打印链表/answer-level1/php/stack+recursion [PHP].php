```
/**
 * Definition for a singly-linked list.
 * class ListNode {
 *     public $val = 0;
 *     public $next = null;
 *     function __construct($val) { $this->val = $val; }
 * }
 */
class Solution {

    /**
     * @param ListNode $head
     * @return Integer[]
     */
    function reversePrint($head) {
        $stack = new SplStack;
        while ($head != null) {
            $stack->push($head);
            $head = $head->next;
        }

        $arr = [];
        $n = $stack->count();
        for ($i = 0; $i < $n; $i++) {
            $arr[$i] = $stack->pop()->val;
        }
        return $arr;
    }

    function reversePrint1($head) {
        $arr = [];
        while ($head != null) {
            array_unshift($arr, $head->val);
            $head = $head->next;
        }
        return $arr;
    }

    function reversePrint2($head) {
        if ($head == NULL) return [];
        
        $arr = [];
        if ($head->next != null) {
            $arr = $this->reversePrint2($head->next);  
        }
        array_push($arr, $head->val);
        return $arr;
    }
}
```
