### 解题思路
此处撰写解题思路
本题是经典的双指针解法，但是比较绕的地方是倒数第一个节点是倒数第0个，虽然这个定义接近于普通人但与程序员的定义恰恰相反，反而让我走了一点弯路。首先声明两个节点等于头部节点，然后让一个指针先走k-1步，然后两个指针再同时往前走，当前面那个指针到达最后一个节点的位置时，后走的节点就到了倒数第k个节点了
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
    function getKthFromEnd($head, $k) {
        //双指针法
        $fistNode = $secondNode = $head;
        for ($i = 0; $i < $k - 1; $i ++) {
            $secondNode = $secondNode->next;
        }
        
        while ($secondNode->next) {
            $fistNode = $fistNode->next;
            $secondNode = $secondNode->next;
        }
        return $fistNode;
    }
}
```