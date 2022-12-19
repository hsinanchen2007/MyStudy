### 解题思路
其实就是利用了递归完成了算法的实现
一开始就是链表末尾，也就是个位
个位相加大于等于10进1，小于10就进行下一位的计算

### 代码
#### go版本
``` go
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
  if (l1 == nil && l2 == nil) {
    return nil
  }
  if (l1 == nil) {
    return l2
  }
  if (l2 == nil) {
    return l1
  }
  sum := l1.Val + l2.Val
  nextNode := addTwoNumbers(l1.Next, l2.Next)
  if sum < 10 {
    return &ListNode{Val:sum, Next:nextNode}
  } else {
    tempNode := &ListNode{Val:1, Next:nil}
    return &ListNode{Val:sum - 10, Next:addTwoNumbers(nextNode, tempNode)}
  }
}
```

#### java版本
```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
      if (l1 == null && l2 == null) {
        return null;
      }
      if (l1 == null) {
        return l2;
      }
      if (l2 == null) {
        return l1;
      }
      int sum = l1.val + l2.val;
      ListNode nextNode = addTwoNumbers(l1.next, l2.next);
      if (sum < 10) {
        ListNode result = new ListNode(sum);
        result.next = nextNode;
        return result;
      } else {
        ListNode temp = new ListNode(1);
        ListNode result = new ListNode(sum - 10);
        result.next = addTwoNumbers(nextNode, temp);
        return result;
      }
    }
}
```