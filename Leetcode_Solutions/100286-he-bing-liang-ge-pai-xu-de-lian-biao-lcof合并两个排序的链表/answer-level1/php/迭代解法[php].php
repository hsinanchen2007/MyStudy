### 解题思路
1、遍历l1、l2，直到l1或者l2为null时退出遍历

2、遍历时比较l1、l2的元素的大小，小的挂在dummy上

3、遍历完成后，再把剩下没遍历的，因为是有序，直接挂在后面。

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
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function mergeTwoLists($l1, $l2) {
        $dummy = new ListNode(0);
        $ret = $dummy;
        while($l1 && $l2){
            if($l1->val<$l2->val){
                $dummy->next = $l1;
                $l1=$l1->next;
            }else{
                $dummy->next = $l2;
                $l2=$l2->next;
            }
            $dummy = $dummy->next;
        }
        $dummy->next = $l1?$l1:$l2;
        return $ret->next;
    }
}
```