这题不应该是简单级别的。

这里反转了链表的后半部分，时间复杂度略高，但是可以不用考虑奇数还是偶数的情况。

何谓快慢指针，其实就是两个指针，一根指针一次移动一个位置，另一个指针一次移动两个位置
- 适合用于有中点相关的场景
- 有中点或倍数的时候可以考虑快慢指针来解决问题

```php
class Solution
{

    /**
     * @param ListNode $head
     * @return Boolean
     */
    function isPalindrome($head)
    {
        // double pointers 快慢指针
        if ($head == null || $head->next == null) {
            return true;
        }

        if ($head->next->next == null) {
            return $head->val == $head->next->val;
        }

        $slow = $head;
        $fast = $head;
        // 边遍历边反转 slow 指针之前的链表
        while ($fast !== null && $fast->next !== null) {
            $slow = $slow->next;
            $fast = $fast->next->next;
        }

        // 用简单示例在纸上画图，可知此时，如果链表总数为偶数，slow 位于右中位
        // 如果为奇数，slow 位于中间位
        // 反转 slow 至 链表尾的链表，使用迭代
        $slow = $this->reverse($slow);

        // 遍历两个链表，比较
        while ($head !== null && $slow !== null) {
            if ($head->val !== $slow->val) {
                return false;
            }

            $head = $head->next;
            $slow = $slow->next;
        }

        return true;
    }

    private function reverse($head)
    {
        if ($head === null || $head->next === null) {
            return $head;
        }

        $last = $this->reverse($head->next);
        $head->next->next = $head;
        $head->next = null;
        return $last;
    }
}
```

