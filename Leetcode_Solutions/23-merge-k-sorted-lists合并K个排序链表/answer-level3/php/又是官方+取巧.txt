### 解题思路
取巧虽然是O(n)但是速度比官方的O(nlog n)快得多得多，有点疑惑

### 代码

```php
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
     * @param ListNode[] $lists
     * @return ListNode
     */
    function mergeKLists($lists) {

        // $l1 = $lists[0];
        // $i = 0;
        // while($i<count($lists)){
        //     $l2 = $lists[$i+1];
        //     $sentry = new ListNode(0);
        //     $curr = $sentry;

        //     while ($l1 != null && $l2 != null) {
        //         if ($l1->val < $l2->val) {
        //             $curr->next = $l1;
        //             $l1 = $l1->next;
        //         } else {
        //             $curr->next = $l2;
        //             $l2 = $l2->next;
        //         }

        //         $curr = $curr->next;
        //     }

        //     $curr->next = $l1 != null ? $l1 : $l2;
            
        //     $l1 = $sentry->next;
        //     $i++;
            
        // }

        // return $l1;


        if (empty($lists)) return null;
        $len = count($lists);
        $back = new ListNode(0);
        $tmpNode = $back;
        $nodeArr = [];
        for ($i = 0; $i < $len; $i++) {
            $tmp = $lists[$i];
            while(!empty($tmp)) {
                $nodeArr[] = $tmp -> val;
                $tmp = $tmp -> next;
            }
        }
        sort($nodeArr);
        $lenS = count($nodeArr);
        for ($j = 0; $j < $lenS; $j++) {
            $tmpNode -> next = new ListNode($nodeArr[$j]);
            $tmpNode = $tmpNode -> next;
        }
        return $back -> next;

    }
}
```