**题目：**
给出两个 **非空** 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 **逆序** 的方式存储的，并且它们的每个节点只能存储 **一位** 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

**示例:**

```
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```

**解法：**

```php []
/**
 * @param ListNode $l1
 * @param ListNode $l2
 * @return ListNode
 */
function addTwoNumbers($l1, $l2) {
    $dummyHead = new ListNode(0);
    $curr = $dummyHead;
    $carry = 0;
    while ($l1 != null || $l2 != null) {
        $x = $l1 != null ? $l1->val : 0;
        $y = $l2 != null ? $l2->val : 0;
        $sum = $carry + $x + $y;
        $carry = (int)($sum / 10);
        $curr->next = new ListNode($sum % 10);
        $curr = $curr->next;
        if ($l1 != null) {
            $l1 = $l1->next;
        }
        if ($l2 != null) {
            $l2 = $l2->next;
        }
    }
    
    if ($carry > 0) {
        $curr->next = new ListNode($carry);
    }
    
    return $dummyHead->next;
}
```

**执行用时：**
16 ms
