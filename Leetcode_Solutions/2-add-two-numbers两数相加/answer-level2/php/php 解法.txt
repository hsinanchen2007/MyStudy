### 写在前面：
   的的确确 php 不太适合来做算法解答 ， 但是看到解答里php的比较少 ，就还是解了下， 比较初略，有兴趣的同学可以改进下。
### 先放结果：
![image.png](https://pic.leetcode-cn.com/467651208e81e464ef6ebbd3566e009ed290f3f2b8178ab8f8d576cbb5619a71-image.png)
### 代码如下：
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
     $t = $l1;
    $k = 0;

    do{

        $val = $t->val + $l2->val + $k;

        $t->val = $val % 10;    

        $k = $val >= 10 ? 1 : 0;

        if (!$l2->next && !$t->next && $k) {
            $t->next = new ListNode(1);
            break;
        }

        if ($t->next && !$l2->next) {
            $l2->next = new ListNode(0);
        }


        if ($l2->next && !$t->next) {
            $t->next = new ListNode(0);
        }            

        $t = $t->next;

        $l2 = $l2->next;

    }while ($t);

    return $l1;
    }
}
```
### 补充说明：
此处用来深浅拷贝的原理，大致如此：A对象 的 a 属性是B对象 ，是指A对象的a属性指针指向B对象， B对象改变是不会影响指针的。