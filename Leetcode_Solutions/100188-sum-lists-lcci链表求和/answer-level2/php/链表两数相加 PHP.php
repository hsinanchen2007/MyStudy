### 解题思路
1、设置哨兵头
2、设置公共sum
3、当前节点取2数之和取余
4、如果2节点之和可以进1位就设置公共sum=1
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
    function addTwoNumbers($l1, $l2) {
        $sum =0;
        $head = new ListNode(null);//设置哨兵头
        $cur = $head;
        while($l1 || $l2 || $sum){
            $a = $b = 0;
            if($l1!==null && $l1->val){
                $a = $l1->val;
            }
            if($l2!==null && $l2->val){
                $b = $l2->val;
            } 
            $sum += $a+$b;//获取同等index之和
            $cur = $cur->next = new ListNode($sum%10);//取10的余数做节点
            if($l1!==null){
                $l1 = $l1->next;//下一节点
            }
            if($l2!==null){
                $l2 = $l2->next;
            }
            $sum = $sum>=10 ? 1:0;//判断如果当前之和大于10则设置全局sum为1（方便下一位进1）
        }
        return $head->next;
    }
}
```