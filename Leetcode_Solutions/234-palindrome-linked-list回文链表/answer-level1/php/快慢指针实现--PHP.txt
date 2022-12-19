### 解题思路
算法：
0、定义快慢指针，fast和slow, slow指向头节点，fast指向头节点下一个节点
1、遍历链表，直到fast指向链表尾部。
2、遍历的时候完成两个事情
2.1 移动fast两步，移动slow一步。当fast到达链表尾部时，slow在链表中间。
2.2 对slow指向过的节点进行反转。即单链表反转
3、遍历完成后，slow的左右各看成一个链表，遍历比对是否一致。

注意：节点数是奇偶的差异
![001.JPG](https://pic.leetcode-cn.com/8ea97772ee9ca088ccc3e5d7ca7f0a26d40dd49739d19b737329eb8f56ec397d-001.JPG)


### 性能
执行用时 :24 ms, 在所有 php 提交中击败了86.54%的用户
内存消耗 :23.1 MB, 在所有 php 提交中击败了97.22%的用户

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
     * @return Boolean
     */
    function isPalindrome($head) {
        if ($head == null OR $head->next == null) {
            return true;
        }

        $fast = $head->next;
        $slow = $head;
        $pre = null;
        $prepre = null;

        while ($fast != null && $fast->next != null) {
            $pre = $slow;
            // 移动快慢指针
            $slow = $slow->next;
            $fast = $fast->next->next;

            // 反转慢指针遍历过的节点
            $pre->next = $prepre;
            $prepre = $pre;
        }

        // 右边的节点构成右链表【为什么是next, 偶数节点好理解，奇数节点思考了很久，因为如果是奇数，中间的节点是不需要比较的】
        $pr = $slow->next;
        // 左边的节点构成左链表【以下两行改成这样是不行的$pl = $fast == null ? $pre : $slow;】
        $slow->next = $pre;
        // fast为空说明是奇数节点
        $pl = $fast == null ? $slow->next : $slow;

        while ($pl != null) {
            if ($pl->val != $pr->val) {
                return false;
            }
            $pl = $pl->next;
            $pr = $pr->next;
        }

        return true;
    }
}
```

### 参考
[https://leetcode-cn.com/problems/palindrome-linked-list/solution/javashi-xian-kuai-man-zhi-zhen-fan-zhuan-qian-ban-/](https://leetcode-cn.com/problems/palindrome-linked-list/solution/javashi-xian-kuai-man-zhi-zhen-fan-zhuan-qian-ban-/)

### 后记
**做了一两个小时，很崩溃。**