### 解题思路
引用2个哨兵结点 一个为奇结点服务 一个为偶结点服务 
遍历   奇结点连接奇结点(oddNext = odd.next.next) 偶结点连接偶结点 当奇结点或偶结点有一方的next为null时退出
然后 将它们连接起来 odd.next = dummyHead2.next;

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
 * @return {ListNode}
 */
var oddEvenList = function(head) {
    if (!head || !head.next) return head;
  const dummyHead1 = { //哨兵结点 指向第一个奇结点
    next: head
  }
  const dummyHead2 = {//指向第一个偶结点
    next: head.next
  }
  let odd = dummyHead1.next;
  let even = dummyHead2.next;
  while (odd && odd.next && even && even.next) {  //遍历 获取下一个结点 改变指向 改变开始结点
    const oddNext = odd.next.next;
    const evenNext = even.next.next;
    odd.next = oddNext;
    even.next = evenNext

    odd = oddNext;
    even = evenNext;
  }
  // 连接
  odd.next = dummyHead2.next;
  return dummyHead1.next;
};
```