### 解题思路

分隔链表 ，定义俩个链表 smaller(小于特定值) greater(大于特定值)
遍历一次将初始链表中所有值加入所定义的俩个链表中(遍历 所以相对位置不会改变)
最后将俩个链表连起来.
有个小技巧就是在初始定义smaller和greater链表时定义了它们的引用dummy...，并且头结点值为-1,
在连接链表的时候就用它们的引用来连接。
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
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
  var smaller = dummySmaller = new ListNode(-1);  //-1 正数?
  var greater = dummyGreater = new ListNode(-1);
  while (head) {
    // console.log(head.val);
    // 链表的遍历
    if (head.val < x) {
      smaller.next = head; //进入较小值分区
      smaller = smaller.next; //更新smaller
    } else {
      greater.next = head;
      greater = greater.next;
    }
    head = head.next;
  }
  // 俩个分区合并
  smaller.next = dummyGreater.next; 
  greater.next = null;
  return dummySmaller.next;  //返回分隔后的头节点
}

```