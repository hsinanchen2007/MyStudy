![Snipaste_2020-03-15_13-46-13.png](https://pic.leetcode-cn.com/c16ee9ed93d355698ee364cca010d7d939d54cd5af342ed1e8220006423e1fc4-Snipaste_2020-03-15_13-46-13.png)

### 解题思路
双指针原地反转，时间复杂度O(n),空间复杂度O(1)。

### 代码

```javascript
var reverseList = function(head) {
    let prev = null;
    let curr = head;
    while (curr !== null) {
        let cnext = curr.next;
        if (prev === null) {
            curr.next = null;
        } else {
            curr.next = prev;
        }
        prev = curr;
        curr = cnext;
    }
    return prev
};
```