- 思路可以看其他人的详细介绍
- 这里贴一下代码和注释
```
var sortList = function (head) {
  if (!head || !head.next) return head;
  let prev1 = new ListNode();
  prev1.next = head;
  /**
   * 
   * @param {*} head1 需要合并的第一个链表的头部节点
   * @param {*} head2 需要合并的第二个链表的头部节点
   * @param {*} prev1 需要合并的第一个链表的头部节点的前一个节点
   * @param {*} prev2 需要合并的第二个链表的头部节点的前一个节点
   * @param {*} num 第一个链表和第二个链表的最大长度
   */
  function merge(head1, head2, prev1, prev2, num) {
    while (num && head2 && head1 !== head2) {
      if (head1.val > head2.val) {
        prev2.next = head2.next;
        head2.next = head1;
        prev1.next = head2;
        head2 = prev2.next;
        prev1 = prev1.next;
        --num;
      } else {
        prev1 = prev1.next;
        head1 = prev1.next;
      }
    }
  }
  // 每个链表的起始长度是1 后面每次乘以二递增
  let num = 1;
  let willContinue = true;
  while (willContinue) {
    let _prev1 = prev1;
    let _prev2 = _prev1;
    // 两个链表的最大长度 用来计算下一个头结点
    let _len = num * 2;
    let _num = num;
    // 链表合并的次数
    let times = 0;
    while (_prev1) {
      _num = num;
      _prev2 = _prev1;
      _len = num * 2;
      while (_num-- && _prev2) {
        _prev2 = _prev2.next;
      }
      if (!_prev2) break;
      ++times;
      merge(_prev1.next, _prev2.next, _prev1, _prev2, num);
      while (_len-- && _prev1) {
        _prev1 = _prev1.next;
      }
      // 链表合并的次数为1 并且准备进行第二次合并时 头结点不存在 说明进行了最后一次合并 结束循环
      if (times === 1 && (!_prev1 || !_prev1.next)) willContinue = false;
    }
    num *= 2;
  }
  return prev1.next;
};
};
```
