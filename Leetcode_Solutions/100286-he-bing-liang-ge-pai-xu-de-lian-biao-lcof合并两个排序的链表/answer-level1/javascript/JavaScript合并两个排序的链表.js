### 解题思路
> 迭代插入

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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function (l1, l2) {
  if(l1 == null) return l2;
  let pl1 = l1 // 提取链表l1指针
 
  function add(val) {
    // val 值过小 比l1头结点还小
    if(val < pl1.val){
      let newListNode = new ListNode(val)
      newListNode.next = pl1
      pl1 = newListNode
      l1 = pl1
      return
    }

    // val 过大 已到达链表l1末尾
    if (pl1.next == null) {
      pl1.next = new ListNode(val)
      return
    }
    // 中间操作
    if (val <= pl1.next.val) {
      let newListNode = new ListNode(val)
      newListNode.next = pl1.next
      pl1.next = newListNode
      return
    }
  // 不满足以上三种情况 继续迭代
    pl1 = pl1.next
    add(val)
  }

   //遍历链表l2
  while (l2 != null) {
    // 把l2插入l1的操作
    add(l2.val)
    l2 = l2.next
  }
  return l1
};
```