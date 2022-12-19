题目要用O(1)空间复杂度，直接想有点困难。
我们先写O(n)的版本，然后再优化为O(1)。

比如head链表是1 2 3 4 5 null
我们建立奇偶两个链表
odd -1
even -1
按照用index变量区分奇偶，遍历head链表分别连到两个链表
odd -1 1 3 5
even -1 2 4 5
注意如果是奇数个，even最后会带着一个node，这时候用pEven.next = null去掉5，even -1 2 4
之后用pOdd指针链接even.next
odd -1 1 3 5 2 4 null
返回odd.next 1 3 5 2 4 null 满足题意

```
var oddEvenList = function(head) {
  if (!head) {
    return null
  }
  
  let odd = new ListNode(-1)
  let even = new ListNode(-1)
  let pOdd = odd
  let pEven = even
  
  let index = 0
  for (let i=head; i!==null; i=i.next) {
    index++
    if (index % 2 !== 0) {
      pOdd.next = i
      pOdd = pOdd.next
    } else {
      pEven.next = i
      pEven = pEven.next
    }
  }
  pEven.next = null
  even = even.next
  pOdd.next = even
  
  return odd.next
};
```

下面我们优化为O(1)的空间复杂度。
把新建两个奇偶链表，改为由第一个元素为odd起点，第二个元素为even起点，
然后遍历剩余元素
odd 1
even 2
剩余 3 4 5 null
遍历后则为
odd 1 3 5
even 2 4 5
同样去掉even的5，pEven.next = null，even 2 4 null
链接odd even， 1 2 5 2 4 null
返回odd

```
var oddEvenList = function(head) {
  if (!head) {
    return null
  }
  
  let odd = head
  let even = head.next
  let pOdd = odd
  let pEven = even
  
  if (even === null) { // 加一个特殊情况的判断，如果链表只有一个结点则直接返回odd或者head
    return odd
  }
  
  let index = 0
  for (let i=even.next; i!==null; i=i.next) {
    index++
    if (index % 2 !== 0) {
      pOdd.next = i
      pOdd = pOdd.next
    } else {
      pEven.next = i
      pEven = pEven.next
    }
  }
  pEven.next = null
  // even = even.next // 注意这里要去掉。因为even是从2开始，不是新建的-1开始的链表
  pOdd.next = even
  
  return odd
};
```
