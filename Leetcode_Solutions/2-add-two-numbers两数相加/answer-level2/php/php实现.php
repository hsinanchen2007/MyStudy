- 状态：通过
- 执行用时：24 ms
- 内存消耗：14.8 MB
- 语言：php

```

/**
 * Definition for a singly-linked list.
 */
class ListNode {
    public $val  = 0;
    public $next = null;
    function __construct($val) { 
        $this->val = $val; 
    }
}

class Solution {
    public function addTwoNumbers($l1, $l2)
    {
        $res = new ListNode(0);

        $p = $l1;
        $q = $l2;

        $carry = 0;
        $curr = $res;
        while ($p != null || $q != null) {
            $x = ($p==null) ? 0 : $p->val;
            $y = ($q==null) ? 0 : $q->val;

            $sum = $x + $y + $carry;
            $carry = 0;
            if ($sum >= 10) {
                $carry = intval($sum/10);
            }

            $curr->next = new ListNode($sum % 10);

            $curr = $curr->next;

            $p = $p->next;
            $q = $q->next;
        }

        if ($carry > 0) {
            $curr->next = new ListNode($carry);
        }
        return $res->next;
    }
}

```