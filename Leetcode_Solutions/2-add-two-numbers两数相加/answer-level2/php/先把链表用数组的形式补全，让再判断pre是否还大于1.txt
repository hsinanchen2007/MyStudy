### 解题思路
此处撰写解题思路

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
class Solution
{

    /**
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function addTwoNumbers($l1, $l2)
    {
        $arr1 = $arr2 = [];
        $re = new ListNode(0);
        /**
         * 补全操作
         */
        while ($l1 || $l2) {
            $arr1[] = !is_null($l1) ? $l1->val : 0;
            $arr2[] = !is_null($l2) ? $l2->val : 0;
            if ($l1) $l1 = $l1->next;
            if ($l2) $l2 = $l2->next;
        }
        $pre = 0;

        for ($i = 0; $i < count($arr1); $i++) {
            $sum = $arr1[$i] + $arr2[$i] + $pre;
            if ($sum >= 10) {
                $pre = 1;
                $sum = $sum - 10;
            } else {
                $pre = 0;
            }
            $cur = $re;
            while (!is_null($cur->next)) {
                $cur = $cur->next;
            }
            $cur->next = new ListNode($sum);
        }

        if ($pre > 0) {
            $cur = $re;
            while (!is_null($cur->next)) {
                $cur = $cur->next;
            }
            $cur->next = new ListNode($pre);
        }

        return $re->next;

    }

}

/*class  ListNode
{
    public $val = 0;
    public $next = null;

    function __construct($val)
    {
        $this->val = $val;
    }
}

function toListNode($arr1)
{
    $l1 = new ListNode(0);
    foreach ($arr1 as $item) {
        $noe = new ListNode($item);
        $cur = $l1;
        while (!is_null($cur->next)) {
            $cur = $cur->next;
        }
        $cur->next = $noe;
    }
    return $l1;
}

$arr1 = [5];
$arr2 = [5];

$l1 = toListNode($arr1);
$l2 = toListNode($arr2);

$s = new  Solution();
$result = $s->addTwoNumbers($l1->next, $l2->next);
var_dump($result);*/



```