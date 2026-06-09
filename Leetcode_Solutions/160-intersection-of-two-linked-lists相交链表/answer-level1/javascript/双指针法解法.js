**解：**

时间复杂度 : $O(n)$
空间复杂度 : $O(1)$

---

附代码及注释：

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */

/**
 * @param {ListNode} headA
 * @param {ListNode} headB
 * @return {ListNode}
 */
var getIntersectionNode = function(headA, headB) {

  // 创建 A 和 B 的头副本
  var lastHeadA = headA;
  var lastHeadB = headB;

  // 初始化 A 和 B 长度用于记录
  var ALen = 0;
  var BLen = 0;

  // 遍历 A 和 B 链表至最后一个 next
  while (lastHeadA && lastHeadA.next !== null) {
    lastHeadA = lastHeadA.next;

    // 计算 A 和 B 链表的长度
    ALen++;
  }
  while (lastHeadB && lastHeadB.next !== null) {
    lastHeadB = lastHeadB.next;
    BLen++;
  }

  // 如果 A 和 B 链表的尾部不相等，说明他们没有相交
  // 一旦相交其尾部必定相等
  if (lastHeadA !== lastHeadB) {
    return null;
  }

  // 用到上面求得的 A 和 B 的长度，计算 A 和 B 的长度差
  // 并将长的链表遍历长度差个数，使得 A 和 B 链表长度一样
  var len = Math.abs(ALen - BLen);
  while (len) {
    if (ALen > BLen) {
      headA = headA.next;
    } else {
      headB = headB.next;
    }
    len--;
  }

  // 因为已经得知尾部相交，现在只需要同步遍历 A 和 B 链表，只要他们一旦相等
  // 就代表这是他们第一个相交的节点，退出循环返回即可
  while (headA !== headB) {
    headA = headA.next;
    headB = headB.next;
  }
  return headA;
};
```
