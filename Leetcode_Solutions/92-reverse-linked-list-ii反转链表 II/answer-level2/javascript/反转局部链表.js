### 解题思路
分3步进行思考
1.如何反转单个链表
2.当处于中间断的链表反转后，它们的首尾指向是怎样的
3.如何保存原来最开始的点
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
 * @param {number} m
 * @param {number} n
 * @return {ListNode}
 */
var reverseBetween = function (head, m, n) {
  //record用于记录最开始的点，也就是后面要返回的值。p用于找到反转的位置
  let p = record = new ListNode();   
  //链表反转需要用到的两边变量pre，cur。start,和end用于标记反转的链表的开始和结尾点      
  let pre, cur, start, tail;                
  p.next = head;      
  //找到开始反转的点，之所以用m-1，因为第m-1个点的next就是启始的点。当局部链表发生反转后，第m-1个点的next指向需要重新指向反转后的启始点                    
  for (let i = 0; i < m - 1; i++) {         
    p = p.next;
  }
  //纪录第m-1个点，这个点在反转后next指向需要重新指向
  start = p;
  //p.next即使为第m个点，它也是局部链表反转之后的最后一个点，标记为tail
  pre = tail = p.next;
  cur = pre.next;
  //进行局部反转
  for (let j = 0; j < n - m; j++) {
    let temp = cur.next;
    cur.next = pre;
    pre = cur;
    cur = temp;
  }
  //第m-1个点的指向需要重新指向
  start.next = pre;
  //由于局部链表已经反转了，那么反转前的第一个点也就是反转后的最后一个点需要重新指向
  tail.next = cur;
  return record.next;
};
```