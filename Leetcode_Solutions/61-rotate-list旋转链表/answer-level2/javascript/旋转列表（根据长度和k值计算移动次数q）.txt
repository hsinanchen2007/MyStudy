> 不同于合并为环的思路，依赖于链表长度，根据长度跟k值计算出需要移动的次数，修改指针next进行旋转

1. 处理边界情况，比如k为0或者链表为空或者链表长度只有1的情况
2. 遍历链表计算得到长度，并标记出末尾的位置
3. 长度跟k值的余数为0时说明没有移动，长度len比k值大时，移动次数为len - k，否则为len - k % len
4. 增加index标识，直到index大于移动次数之前，不断自增，并且移动指针
5. 遍历完成后可以把指针指向需要分割的位置，改变指针next即可得到结果

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
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
  /** 边界情况 */
  if (k === 0) { return head; }
  if (head === null || head.next === null) {
    return head;
  }

  let len = 0;
  let cursor = head;
  let tailEnd = null;
  
  /** 计算长度 */
  while (cursor) {
    if (cursor.next === null) {
      tailEnd = cursor;
    }
    len++;
    cursor = cursor.next;
  }
  
  if (k === len || k % len === 0) { return head; }
  
  /** 设置移动数量 */
  const q = len > k ? len - k : len - k % len;
  
  let index = 1;
  let headFloat = head;
  let tailStart = null;
  while (index < q) {
    index++;
    headFloat = headFloat.next;
  }
  tailStart = headFloat.next;
  headFloat.next = tailEnd.next;
  tailEnd.next = head;
  return tailStart;
};
```