### 解题思路
掌握单链表的反转后，处理好分组，按分组来反转比较好理解。

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :16.6 MB, 在所有 PHP 提交中击败了13.16%的用户

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
     * @param ListNode $head
     * @param Integer $k
     * @return ListNode
     */
    function reverseKGroup($head, $k) {
        $pre = null;
        $cur = $head;
        $next = null;
        $check = $head;
        $can_reverse = 0;

        // 分出当前组(长度)$k)
        while ($can_reverse < $k && $check != null) {
            $can_reverse++;
            $check = $check->next;
        }

        // 如果长度小于$k, 不反转，直接返回头节点
        if ($can_reverse != $k) return $head;

        // 反转当前组
        $count = 0;
        while ($count < $k && $cur != null) {
            $next = $cur->next;
            $cur->next = $pre;
            $pre = $cur;
            $cur = $next;
            $count++;
        }

        // 如果有下一组，递归反转下一组
        if ($next != null) $head->next = $this->reverseKGroup($next, $k);

        return $pre;
    }
}
```

### 算法复杂度
- 时间复杂度 O(N) 【应该是吧】
- 空间复杂度 O(1)

### 参考
[https://leetcode-cn.com/problems/reverse-nodes-in-k-group/comments/2253](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/comments/2253)