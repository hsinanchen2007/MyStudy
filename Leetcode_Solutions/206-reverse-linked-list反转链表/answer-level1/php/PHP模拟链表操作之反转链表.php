### 解题思路
1. 边界条件
2. 当前节点
3. 当前节点上一节点
4. 边界条件
5. 防止断链 (第 8 步)
6. 反转 (当前节点的后指针为当前节点的上一节点)
7. 保存当前节点, 用于迭代 (第 6 步)
8. 指针后移

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
     * @param ListNode $listNode
     * @return ListNode
     */
    function reverseList($listNode) {
        if ($listNode === null || $listNode->next === null) {
			return $listNode;
		}

		$currentNode = $listNode;

		$prevNode = null;

		while ($currentNode !== null) { 
			$nextNode = $currentNode->next;
			$currentNode->next = $prevNode;
			$prevNode = $currentNode;
			$currentNode = $nextNode;
		}

		return $prevNode;
    }
}
```