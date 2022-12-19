## 第一版，使用数组辅助。把它的每个节点在一个数组中按顺序存下来
> 80ms,34M。
```javascript []
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
  const arr = [head];
  for (let cur = head; cur.next; cur = cur.next) {
    arr.push(cur.next);
  }
  if (arr.length === 1) return null;
  if (n > 1) {
    arr[arr.length - n].val = arr[arr.length - n].next.val;
    arr[arr.length - n].next = arr[arr.length - n].next.next;
  } else arr[arr.length - n - 1].next = null;
  return arr[0];
};
```


## 第二版。看了官方题解，使用双指针方法，但是不想为了删除头节点这一特殊情况而额外增加哑结点来辅助
> 76ms,34M。
```javascript []
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
  let first = head;
  for (let i = 0; i < n; i++) {
    first = first.next;
  }
  if (!first) return head.next; // 当n=链表长度时，此时需要删除第一个节点

  let second = head;
  while (first.next) {
    first = first.next;
    second = second.next;
  }
  second.next = second.next.next;
  return head;
};
```