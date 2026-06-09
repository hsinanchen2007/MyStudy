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
 * @return {ListNode}
 */
var middleNode = function(head) {
    let headVal = head.next;
    const arr = [];
    let newArr = [];
    arr.push(head.val)
    for (let i = 0; i <= 100; i++) {
        if (headVal !== null) {
            arr.push(headVal.val);
            headVal = headVal.next;
        } else {
            break;
        }
    }

    if (arr.length === 1) {
        return { val: arr[0], next: null }
    }

    if (arr.length === 2) {
        return { val: arr[1], next: null }
    }

    if (arr.length % 2 === 0) {
        newArr = arr.slice(arr.length/2)
    } else {
        newArr = arr.slice(parseInt((arr.length)/2))
    }

    const ans = {};
    if (newArr.length === 2) {
        return {
            val: newArr[0],
            next: {
                val: newArr[1],
                next: null,
            }
        }
    }

    ans.val = newArr[0];
    ans.next = { val: '', next: {} }
    let ansVal = ans.next;

    for (let i = 1; i < newArr.length; i++) {
        if (i === newArr.length - 1) {
            ansVal.val = newArr[i];
            ansVal = null;
        } else {
            ansVal.val = newArr[i];
            ansVal = ansVal.next = {};
        }
    }

    return ans;
};
```