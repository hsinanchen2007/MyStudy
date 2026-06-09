### 解题思路
1. 将链表l1, l2转换为数组
2. 补齐空位，使其有相同的长度（当然也可以跳过，取Math.max的length也可以）
3. 按后进先出逐个取出数组中的数组，维护一个遍历next，每次得到相加后的ListNode后，将next至为当前ListNode
4. 将next指向当前ListNode，开始计算下一个ListNode，（同时维护进位变量）
5. 当数组完成遍历后，next就是所需要的链表head

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
var addTwoNumbers = function(l1, l2) {
  const list1 = []
  const list2 = []

  let node1 = l1
  let node2 = l2
  while (node1) {
    list1.push(node1.val)
    node1 = node1.next
  }

  while (node2) {
    list2.push(node2.val)
    node2 = node2.next
  }

  // 补齐空位
  while (list1.length !== list2.length) {
    if (list1.length > list2.length) {
      list2.unshift(0)
    } else {
      list1.unshift(0)
    }
  }

  let next = null
  let carry = 0// 进位变量

  // 这里同时将carry也作为条件是为了处理链表第一个节点相加也需要进位的场景
  while (list1.length || carry) {
    const n1 = list1.pop() || 0
    const n2 = list2.pop() || 0
    let sum = n1 + n2 + carry
    if (sum > 9) {
      sum -= 10
      carry = 1
    } else {
      carry = 0
    }

    const dummy = new ListNode(sum)// 创建当前节点
    dummy.next = next// next指向上一节点
    next = dummy// 将next至为当前节点，下次循环用
  }

  return next
};
```