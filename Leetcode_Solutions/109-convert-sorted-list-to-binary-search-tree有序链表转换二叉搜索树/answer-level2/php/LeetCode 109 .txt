### 解题思路
1、核心思想还是找到中间近似值
2、链表采用双指针去取中间值 慢指针走1布 快指针走2布，快指针走到尾部的时候，慢指针走到中间
3、$tmp 是为了保存中间值前一位也就是左子树
4、$tmp->next = null 是为了只截取链表的左子树
5、$slow_ptr->next 是右子树

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
/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($value) { $this->val = $value; }
 * }
 */
class Solution {

    /**
     * @param ListNode $head
     * @return TreeNode
     */
    function sortedListToBST($head)
    {
        //终止条件
        if ($head ==null) return null;
        if ($head->next ==null) return new TreeNode($head->val);
    
        $slow_ptr = $head;//慢指针
        $fast_ptr = $head;//快指针
        $temp = null;
        while ($fast_ptr!=null && $fast_ptr->next!=null) {
            $fast_ptr = $fast_ptr->next->next;
            $tmp = $slow_ptr;
            $slow_ptr = $slow_ptr->next;
        }
        $left = $head;
        $right = $slow_ptr->next;//右子树链表
        $tmp->next = null;//链表中间位左边一位设为null,此时head 只剩左子树链表
        $root = new TreeNode($slow_ptr->val);
        $root->left = $this->sortedListToBST($left);
        $root->right = $this->sortedListToBST($right);
        return $root; 
    }
}
```