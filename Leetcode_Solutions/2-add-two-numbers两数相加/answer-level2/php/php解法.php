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
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function addTwoNumbers($l1, $l2) {
        $result = '';
        $tmp = &$result;
        $carry = 0;
        while (true) {
            if ($l1 == null && $l2 == null) {
                if ($carry) {
                    $tmp = new ListNode($carry);
                }
                break;
            }
            if ($l1 != null) {
                $value1 = $l1->val;
                $l1 = $l1->next;
            } else {
                $value1 = 0;
            }
            if ($l2 != null) {
                $value2 = $l2->val;
                $l2 = $l2->next;
            } else {
                $value2 = 0;
            }
            $sum = $value1 + $value2 + $carry;
            if($sum >=10){
                $tmp = new ListNode($sum - 10);
                $carry = 1;
            }else{
                $tmp = new ListNode($sum);
                $carry = 0;
            }        
            $tmp = &$tmp->next;
        }
        return $result;
    }
}
```
![image.png](https://pic.leetcode-cn.com/24e5c5c72e0b06731f8e9c633a54c4a0708429f9e133181400a116f58bfe3b28-image.png)

## 这道题考得是引用传值。

- 一开始没搞懂链表的概念，拿数组在做，一直报错，后面打印了一下$l1才明白怎么回事，然后开头注释里提供了实例化链表的类。
- 先不管链表，如果说这是一个数组，那简单了，遍历一个长的，然后依次相加，碰到大于10的进位就完事。
- 然后这题是链表，
- 按照刚才的思路，
- 第一个元素:`$l1->val+$l2->val`;
- 第二个元素:`$l1->next->val+$l2->next->val`;
- 第三个个元素:`$l1->next->next->val+$l2->next->next->val`;
- ...

- 直接这么写会很麻烦。
- 换一个思路，第一个元素加完之后，用另一个变量`$a把$l1->next`存起来，计算第二个元素的时候就可以直接用`$a->val`了。
- 答案中直接用的`$l1`本身，因为第一个元素加完之后已经没有用了。

- 同样的道理，保存计算结果的`$result`也是同样的办法，引入了一个中间量$tmp用来保存next的值
![image.png](https://pic.leetcode-cn.com/987e75f4d1eac4b0316bb69f27aadae34bb45bb26c71ba1253cae4be606b9054-image.png)

- 参考其他人答案，发现用`$sum>10`做判断比直接`$sum%10`和$`sum/10`得出余数和进位要快