### 解题思路
大体思路：
- 先创建两个头结点分别用于连接小于部分和大于等于部分
- 遍历该链表，若当前结点小于x,将其插到小于的链表上否则插到大于链表上。
- 遍历完毕后，将大于等于部分链表的连到小于部分的后面即可.

学习自[分割链表(java双百)](https://leetcode-cn.com/problems/partition-list-lcci/solution/fen-ge-lian-biao-javashuang-bai-by-bu-xiu-gang-pen/)

### 代码

```golang
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func partition(head *ListNode, x int) *ListNode {
  preHead := &ListNode{Val:-1} // 创建头节点，连接小于x的部分
  nxtHead := &ListNode{Val:-1} // 创建头节点，连接大于x的部分
  preCurrent := preHead // 连接小于x部分的游标
  nxtCurrent := nxtHead // 连接大于x部分的游标
  current := head // 当前游标
  for current != nil { // 遍历该链表
    if current.Val < x { // 若当前节点小于x
      preCurrent.Next = current // 将其插到小于x的链表上
      preCurrent = preCurrent.Next // 移动小于x部分链表的游标
    } else { // 若当前节点大于x
      nxtCurrent.Next = current // 将其插到大于x的链表上
      nxtCurrent = nxtCurrent.Next // 移动大于x部分链表的游标
    }
    current=current.Next // 移动当前游标
  }
  // 遍历链表结束，将大于等于x的部分链表连到小于x部分的链表后面
  preCurrent.Next = nxtHead.Next 
  // 将大于等于x部分的链表尾指针置空
  nxtCurrent.Next = nil
  // 返回构建新的链表的头节点即可
  return preHead.Next
}
```