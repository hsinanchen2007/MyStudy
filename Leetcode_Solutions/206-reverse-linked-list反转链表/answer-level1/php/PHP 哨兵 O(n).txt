### 解题思路
此处撰写解题思路
本题php的解法首先要声明一个哨兵为接下来的处理奠定基础。
假设哨兵结点为root，则root->next = head;
以root->2->1->3->4->5->null为例，下一步要将3拿出来讲解过程
1. 第一步，将1和4连接，声明临时变量存储3
2. 第二步，将3放到root后面，声明临时变量存储2
3. 第三步，将3和2连接
此时也就完成了交换的步骤。

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
    function reverseList($head) {
        $root = new ListNode(0);
        $root->next = $head;
        while ($head->next) {
            $tmp1 = $head->next;
            $head->next = $tmp1->next;
            $tmp2 = $root->next;
            $root->next = $tmp1;
            $tmp1->next = $tmp2;
        }
        return $root->next;
    }
}
```