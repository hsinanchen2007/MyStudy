### 解题思路

跟其他人的思路差不多

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
    let res = new ListNode(null);
    let L1 = l1;
    let L2 = l2;
    let nextFlag = res;//游标
    let countFlag = 0; //进位
    while(L1 || L2 || countFlag){
        let count1 = L1 == null ? 0 : L1.val;
        let count2 = L2 == null ? 0 :L2.val;
        let sum = count1 + count2+ countFlag;//求和
        let countNum = sum % 10;
        countFlag = sum >= 10 ? 1:0;
        nextFlag.val = countNum;

        L1= L1 == null ? null : L1.next;
        L2= L2 == null ? null :L2.next;

        if(L1 || L2 || countFlag){
            let node = new ListNode(null);
            nextFlag.next = node;
            nextFlag = node;
        }
    }
    return res;

};
```