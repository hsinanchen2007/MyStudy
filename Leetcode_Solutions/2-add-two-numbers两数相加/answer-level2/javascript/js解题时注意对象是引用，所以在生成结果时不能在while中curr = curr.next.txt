### 解题思路

思路跟其他解法无异。
使用js解题时要注意对象是引用，所以在生成结果时不能在while中curr = curr.next

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
    let tmp = 0;
    let res = new ListNode();

    function gen(l1, l2 , obj = res) {
        const tmpSum = l1.val + l2.val + tmp;
        if(tmpSum > 9) {
            tmp = 1;
            obj.val = tmpSum - 10;
        } else {
            tmp = 0;
            obj.val = tmpSum;
        }
        if(l1.next || l2.next || tmp) {
            obj.next = new ListNode();
            gen(l1.next || {val: 0}, l2.next || {val: 0}, obj.next)

        }
    }

    gen(l1, l2, res);

    return res;
};
```