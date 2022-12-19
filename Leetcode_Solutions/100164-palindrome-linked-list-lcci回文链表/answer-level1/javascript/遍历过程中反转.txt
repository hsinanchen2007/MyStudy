### 解题思路
此处撰写解题思路

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
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
  if(!head || !head.next) return true
  let flow = fast = new ListNode()
  fast.next = head
  let cur = head
  let pre = null
  while(fast && fast.next){
    fast = fast.next.next
    let tmp = cur.next
    cur.next = pre
    pre = cur
    cur = flow = tmp
  }
  if(!fast) pre = pre.next
  while(pre){
    if(cur.val === pre.val){
      cur = cur.next
      pre = pre.next
    }else{
      return false
    }
  }
  return true
};
```