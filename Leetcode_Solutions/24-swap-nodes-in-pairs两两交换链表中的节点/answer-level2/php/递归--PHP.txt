### 解题思路
两两交换，递归一次，直到链表尾部。

可以简单看成两个节点的一次递归过程，第一个节点a, 第二个节点b
[a->b]->[c->d]
- 把第二个节点b的next作为下一次递归的参数，返回值为下一个子链表，正好是第一个节点的next
- 然后把b的next指向第一个节点

注：以上两步不可反


### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了8.11%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了69.88%的用户

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
     * @return ListNode
     */
    function swapPairs($head) {
        if ($head == null || $head->next == null) return $head;

        $first_node = $head;
        $second_node = $head->next;
        // 以下两行不能写反了
        $first_node->next = $this->swapPairs($second_node->next);
        $second_node->next = $first_node;

        return $second_node;
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)

### 参考
[https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/liang-liang-jiao-huan-lian-biao-zhong-de-jie-di-19/](https://leetcode-cn.com/problems/swap-nodes-in-pairs/solution/liang-liang-jiao-huan-lian-biao-zhong-de-jie-di-19/)