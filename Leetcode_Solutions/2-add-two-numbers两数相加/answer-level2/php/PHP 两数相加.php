```
/*
题解：

    2->4->3
    5->6->4
    【遍历终止条件】
        两条链表都是空的，才会终止；
    【长度问题】
        对于一些简单if的判断，我们可以用三元运算符，比较快；
        如果为空的话，我们给一个默认值0
            例如 1 + 9 9 => 0 1 + 9 9 => 1 0 0
    【进位】$carry
        对于 4+6 会产生进位，那么我们将这个是否进位用 $carry保存
        然后再每一次遍历的时候，计算两个对应位置$x+$y 之和 再加上进位$carry。得到当前位置的$sum
            然后把重置carry = 0
            但是需要判断 $sum
                是否又需要进位，从而得到新的carry
    【最后一位】
        如果两个长度的链表 ，最后求和，可能会超出这个长度
            例如 5 + 5 => 0 1
            所以最后的进位，边界值 也要判断一下才行。

时间复杂度O(max(m, n))
空间复杂度O(max(m, n))

        执行用时 :28 ms, 在所有 PHP 提交中击败了58.73%的用户
        内存消耗 :14.7 MB, 在所有 PHP 提交中击败了55.67%的用户
*/
class Solution {
    /**
     * @param ListNode $l1
     * @param ListNode $l2
     * @return ListNode
     */
    function addTwoNumbers($l1, $l2) {
          $p   = $l1;
          $q   = $l2;
          $carry = 0;//某个位置 的进位

          $out = new ListNode(0);//链表的题目时一般都设个虚拟节点，方便操作
          $cur = $out;//这里是引用 对象
          while ($p != null  || $q != null ) {
              $x = !empty($p) ? $p->val : 0;
              $y = !empty($q) ? $q->val : 0;

              $sum = $x + $y + $carry;//当前位的值
              $carry= 0;//重置为0
              if($sum >= 10) {
                    $carry = intval($sum/10);//如果需要进位
              }

              $cur->next = new ListNode($sum%10);//赋值给当前节点
              $cur = $cur->next; //这个cur 表示每个位的值， 同时引用的out，所以之后out会把每个值连起来
              //继续向下遍历 直到两个都是null
              ($p != null) && ($p = $p->next);
              ($q != null) && ($q = $q->next);
          }
          //如果最后 还有进位 要新加节点了
          if($carry > 0) {
              $cur->next = new ListNode($carry);
          }
          return $out->next;//因为一开始有一个0的初始节点
    }


}

```
