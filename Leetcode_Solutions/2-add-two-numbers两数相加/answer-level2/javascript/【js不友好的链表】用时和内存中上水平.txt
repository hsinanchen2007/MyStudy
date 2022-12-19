### 解题思路
因为不懂链表，所以前期花费了很久看题
大致思路就是，新建一个链表，新建一个current表示当前位置，然后把每次相加得到的值放进去，放进去的时候也要new一个ListNode
然后所有位置都往下走一步
其中因为有进位，所以要有一个变量存进位
具体步骤见代码，很多注释


ps:发现代码提交时间跟网速有很大的关系，有时能击败90%。
执行用时 : 136 ms, 在所有 JavaScript 提交中击败了53.24%的用户
内存消耗 :38.4 MB, 在所有 JavaScript 提交中击败了84.21%的用户

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
  let res = new ListNode(0)
  let current = res
  let upNum = 0
  // sum放在while外面，纯粹为了降低内存
  let sum = 0
  // l1，l2分别是当前位置，upNum是为了判断当前是否还有进位
  while(l1 !== null || l2 !== null || upNum) {
    // sum是l1、l2当前位置的值的和，加上之前的进位
    sum = (l1 !== null ? l1.val : 0) + (l2 !== null ? l2.val : 0) + upNum
    // 加判断纯粹是为了降低一点点时间和内存。其实直接写也可以
    if (sum >= 10) {
      // 获取需要进位的大小upNum
      upNum = Math.floor(sum / 10)
      // sum取余，写入current，也就是res，的下一位
      current.next = new ListNode(sum % 10)
    } else {
      upNum = 0
      current.next = new ListNode(sum)
    }
    // current、l1、l2分别走到下一位置，其中l1,l2要注意位数不一致的情况
    current = current.next
    l1 = l1 !== null ? l1.next : null
    l2 = l2 !== null ? l2.next : null
  }
  // 因为res的位置是0，所以输出res.next
  return res.next
};
```