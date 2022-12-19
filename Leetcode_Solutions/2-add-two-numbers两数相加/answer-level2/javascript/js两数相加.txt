### 解题思路
就像笔算加法一样，一位一位向前加，注意进位

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
    let result = null;
    let curNode = null;
    let curL1Node = l1;
    let curL2Node = l2;
    let nodeCarry = 0;
    
    const resolveNode = (node) => {
        let val = 0;
        let next = null;

        if (node) {
            if (typeof node.val === 'number') {
                val = node.val;
            }

            if (node.next instanceof ListNode) {
                next = node.next;
            }
        }

        return [val, next];
    };

    while(curL1Node || curL2Node || nodeCarry) {
        const [l1Val, l1NextNode] = resolveNode(curL1Node);
        const [l2Val, l2NextNode] = resolveNode(curL2Node);
        const sum = l1Val + l2Val + nodeCarry;
        const newNode = new ListNode(sum % 10);

        nodeCarry = Math.floor(sum / 10);

        if (!result) {
            result = newNode;
            curNode = newNode;
        } else {
            curNode.next = newNode;
            curNode = newNode;
        }

        curL1Node = l1NextNode;
        curL2Node = l2NextNode
    }

    return result;
};
```