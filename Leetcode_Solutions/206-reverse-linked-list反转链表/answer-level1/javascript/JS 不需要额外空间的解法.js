### 解题思路
先声明一个变量暂存一下每次，取下来的链表头结点，先去取下来的头结点做为新的头接单，之前取下的作为尾结点。依次类推。斩断过去，循环迭代。
### 代码
```js
var reverseList = function (head) {
  if(head == null) return null;
  let pHead;
  while (head != null) {
    let temp = head.next
    // head next 和 phead 发生交换
    head.next = null
    head.next = pHead
    pHead = head
    head = temp
  }
  return pHead
};
```

