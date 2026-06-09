### 解题思路
先把head转成字符串，再用parseInt（string,2）转成2进制
在解题时，最开始我把head存储为数字的形式，number= number*10+head.val 后来发现存成数字会有单位长度的限制。
但是存成字符形式就不会有长度的限制了。

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
 * @return {number}
 */
var getDecimalValue = function(head) {
    let number = '';
    while(head){
        number += head.val
        head = head.next;
    }
    return  parseInt(number,2)
};
```