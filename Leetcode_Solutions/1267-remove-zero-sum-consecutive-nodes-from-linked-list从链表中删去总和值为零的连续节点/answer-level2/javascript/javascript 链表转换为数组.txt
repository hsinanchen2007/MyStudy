### 解题思路
链表转换为数组，取出合为0的序列后，在转换为链表

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
 * @return {ListNode}
 */
var removeZeroSumSublists = function(head) {
    const temp = []
    while (head) {
        temp.push(head.val)
        head = head.next
    }
    for (let i = 0; i < temp.length; i++) {
        let start = i
        let end = i
        let sum = temp[i]
        if (sum === 0) {
            temp.splice(i, 1)
            i -- 
        } else {
            for (let j = i + 1; j < temp.length; j++) {
                sum += temp[j]
                end ++
                if (sum === 0) {
                    temp.splice(i, end - start + 1)
                    i -- 
                    break
                }
            }
        }
    }
    let node = null
    if (temp.length) {
        node = new ListNode(temp[0])
        let cur = node
        let i = 1
        while (temp[i]) {
            cur.next = new ListNode(temp[i])
            cur = cur.next
            i ++
        }
    }
    return node
};
```