### 解题思路
![image.png](https://pic.leetcode-cn.com/61142770768fe2b09526e5f06f213d3098135cf957b3bbaa533720e75af9bde9-image.png)
因为是逆序，+10 向后进位
```
    2 -> 4 -> 3 
    5 -> 6 -> 4 +
    --------------
    7 -> 0 -> 8
```
注意： 第二列 4+6 进一位，向后进   3 + 4 + 1 = 8 

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
    let node = new ListNode('head')
    let temp = node , sum , n = 0
    while( l1 || l2 ){
        const n1 = l1 ? l1.val : 0
        const n2 = l2 ? l2.val : 0
        sum = n1 + n2 + n
        temp.next = new ListNode( sum % 10 )
        temp = temp.next
        n = parseInt( sum / 10 )
        if(l1) l1 = l1.next
        if(l2) l2 = l2.next
    }
    if( n > 0 ) temp.next = new ListNode(n)
    return node.next
};
```