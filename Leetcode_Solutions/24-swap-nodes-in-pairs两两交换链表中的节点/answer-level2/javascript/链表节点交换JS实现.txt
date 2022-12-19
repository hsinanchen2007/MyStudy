### 解题思路
1. 2指针+数组法
2. 4指针法

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
var swapPairs = function(head) {
    if (!(head && head.next)) {
        return head
    }
    let p1 = head, p2 = p1 ? p1.next : null, arr = []
    while (p1) {
        if (p2) {
            arr.push(p2)
        }
        arr.push(p1)
        p1 = p2 ? p2.next : null
        p2 = p1 ? p1.next : null
    }
    arr.forEach((item, index) => {
        let ni = arr[index+1]
        item.next = ni ? ni : null
    })
    return arr[0]
};
```