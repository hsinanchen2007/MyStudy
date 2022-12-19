整个思路很简单，把当前元素的Next指针指向前一个元素。

所以需要记录前一个值的地址，然后把当前指针的Next做了记录以后指向前一个值。

之所以需要先做记录是因为指向了前一个值之后就找不到原本指向的下一个值了呀。

初始化前一个元素地址为空。
记录下一个元素的位置 nextHead = head.Next
将当前元素的Next指针指向前 head.Next = prev
前一个元素指向当前元素 prev = head
当前元素指向下一个元素 head = nextHead

实际上下面的递归解法只是把迭代解法稍微做了个转换而已...

```go
 // ReverseListIteration 迭代解法
  func ReverseListIteration(head *leetcode.ListNode) *leetcode.ListNode {
      var prev *leetcode.ListNode

      for head != nil {
          // nextHead := head.Next
          // head.Next = prev
          // prev = head
          // head = nextHead

          head.Next, prev, head = prev, head, head.Next
      }

      return prev
  }

  // ReversetListRecursion 递归解法
  func ReversetListRecursion(prev, head *leetcode.ListNode) *leetcode.ListNode {
      if head == nil {
          return prev
      }

      head.Next, prev, head = prev, head, head.Next
      return ReversetListRecursion(prev, head)
  }
```
