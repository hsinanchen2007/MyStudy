## 迭代解法

```php
class Solution
{
    /**
     * @param ListNode $head
     * @return ListNode
     */
    function reverseList($head)
    {
        // double pointer
        // 我们可以申请两个指针，第一个指针叫 prev，最初是指向 null 的。
        // 第二个指针 cur 指向 head，然后不断遍历 cur。
        // 每次迭代到 cur，都将 cur 的 next 指向 pre，然后 pre 和 cur 前进一位。
        // 都迭代完了 (cur 变成 null 了)，pre 就是最后一个节点了。
        $prev = null;
        $cur = $head;
        while ($cur) {
            $next = $cur->next;
            $cur->next = $prev;
            $prev = $cur;
            $cur = $next;
        }

        return $prev;
    }
}
```


## 递归解法

```php
class Solution {

    /**
     * @param ListNode $head
     * @return ListNode
     */
     // 明确递归函数的含义：传入一个链表（或片段），将其反转，并返回链表头元素
     // 所以，完全反转以后，原来的最后一个元素就变为了链表头元素
    function reverseList($head) {
        if ($head->next == null) {
            return $head;
        }

        $last = $this->reverseList($head->next);
        $head->next->next = $head;
        $head->next = null;

        return $last;
    }
}
```
