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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    let res = new ListNode(0);
    let cursor = res;
    let carry = 0;
    while(l1 != null || l2 != null || carry != 0){
        if(l1 == null && l2 != null && carry == 0){
            //如果 其中一个 等于null了 直接把 另外一个剩下的赋予 结果即可
            cursor.next = l2;
            l2 = null;
        }else if(l2 == null && l1 != null && carry == 0){
            //如果 其中一个 等于null了 直接把 另外一个剩下的赋予 结果即可
            cursor.next = l1;
            l1 = null;
        }else{
            let l1val = l1 != null ? l1.val : 0;
            let l2val = l2 != null ? l2.val : 0;

            let sumval = l1val + l2val + carry;

            carry = parseInt(sumval / 10);

            let sumNode = new ListNode(sumval % 10);

            cursor.next = sumNode;

            cursor = sumNode;
            if(l1 != null) l1 = l1.next;
            if(l2 != null) l2 = l2.next;
        }
    }
    return res.next;
};
```