### 解题思路
最优解要求空间复杂度为On，因此排除掉可能使用额外数组空间的可能
如果要考虑判断回文链表，势必存在首尾放在一起判断的场景，排除掉使用数组，还能将链表原地翻转，进行首尾比较
因为要判断的是回文串，所以将链表的另一半翻转即可。找到链表的中心点，可以马上联想到使用快慢指针。

总结出解题思路：
1. 通过快慢指针找到中心点
2. 将链表后半部分翻转，返回翻转后的节点
3. 翻转后的节点（尾）与原链表节点（首）依次比较，直到翻转后的链表全部比较完成

### 代码

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
  if (!head) return true
  let slow = head
  let fast = head.next// 快指针先走一步，以兼容[1，2]只有两个节点的场景场景

  while (fast && fast.next) {
    slow = slow.next
    fast = fast.next.next
  }

  function reverse(headNode) {
    let dummy = null

    while (headNode) {
      const next = headNode.next
      headNode.next = dummy
      dummy = headNode

      headNode = next
    }

    return dummy
  }

  let reversedHead = reverse(slow.next)// 得到翻转后的节点，e.g., [1,2,3,4,5]会得到5，翻转后的链表为[5,4]

  let start = head
  while (reversedHead) {// 遍历经过翻转的列表，翻转后链表的最后一项为null
    if (start.val !== reversedHead.val) return false

    start = start.next
    reversedHead = reversedHead.next
  }

  return true
};
```