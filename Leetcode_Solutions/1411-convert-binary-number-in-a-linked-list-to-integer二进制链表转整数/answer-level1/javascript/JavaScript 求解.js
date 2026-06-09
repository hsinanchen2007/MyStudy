### 解题思路
![image.png](https://pic.leetcode-cn.com/06d2a0195041865e0f3dd65774be293c7a0a65dbc2e384595d51a84ef7cc8856-image.png)

- 转化为字符串
- parseInt（）转化为十进制

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