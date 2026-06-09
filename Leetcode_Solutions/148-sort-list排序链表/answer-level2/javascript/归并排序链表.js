题目要求的时间复杂度为O(nlogn)，包含logn，很容易想到会用到二分法，把链表逐个划分为节点，使用双指针排序。

- 递归法的归并排序

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
 * @return {ListNode}
 */
var sortList = function(head) {
  if (head === null || head.next === null) {
    return head;
  }
  return cut(head);
};

var cut = function (head) {
  if (head === null || head.next === null) {
    return head;
  }
  /** 快慢指针分出两个片段 */
  let slow = head;
  let fast = head;
  while (fast !== null) {
    fast = fast.next;
    fast = fast !== null ? fast.next : null;
    if (fast !== null) {
      slow = slow.next;
    }
  }
  let half = slow.next;
  slow.next = null;
  let left = cut(head);
  let right = cut(half);
  return merge(left, right);
}

var merge = function (left, right) {
  /** 合并左右两个节点 */
  let res = null;
  let h = res;
  let tmpL = left;
  let tmpR = right;
  while (tmpL !== null || tmpR !== null) {
    if (tmpL === null) {
      h.next = tmpR;
      break;
    } else if (tmpR === null) {
      h.next = tmpL;
      break;
    }
    let tmp = null;
    if (tmpL.val >= tmpR.val) {
      tmp = tmpR;
      tmpR = tmpR.next;
    } else {
      tmp = tmpL;
      tmpL = tmpL.next;
    }
    if (res === null) {
      res = tmp;
      h = res;
    } else {
      h.next = tmp;
      h = h.next;
    }
  }
  return res;
}
```