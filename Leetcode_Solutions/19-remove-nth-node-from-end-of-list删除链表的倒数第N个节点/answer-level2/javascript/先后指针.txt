先后指针：快指针先走n-1步后慢指针再开始从头节点开始走。当快指针走到最后一个结点的时候，慢指针就走到了倒数第N个结点。   
证明：   
1. 假设总共有N个结点，则倒数第n个结点就是正数第N-n+1个结点。   
2. 从头结点正向走到第N-n+1个结点需要走N-n步。
3. 而从头节点到链表最后一个结点需要走N-1步，所以还剩n+1步。    

如果你也使用 JavaScript 解题的话，可以[戳这里](https://github.com/DangoSky/algorithm/tree/master/LeetCode)哦，对一些题目有疑问的话可以一起交流交流~
```
var removeNthFromEnd = function(head, n) {
  // 先指针先走n-1步
  let fast = head;
  for(let i=1; i<=n-1; i++) {
    fast = fast.next;
  }
  let slow = head;
  // 缓存要删除结点的前一个结点
  let pre = null;
  while(fast.next) {
    pre = slow;
    fast = fast.next;
    slow = slow.next;
  }
  // 如果要删除的结点是第一个结点的话，则直接返回slow.next
  if(pre === null) {
    return slow.next;
  }
  else {
    pre.next = slow.next;
  }
  return head;
}
```