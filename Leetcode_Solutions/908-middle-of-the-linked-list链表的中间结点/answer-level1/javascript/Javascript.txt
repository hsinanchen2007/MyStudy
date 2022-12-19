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
    var count = 0
    var curt = head
    //首先计算有多少个节点
    while (curt) {
        curt = curt.next
        count++
    }

    //计算出有多少节点后数着数让他一直等于next就好了
    var ans = head
    for (var i = 1; i < Math.ceil(count / 2); i++) {
        ans = ans.next
    }

    //如果一共有偶数个节点，则返回ans.next，否则返回ans
    if (count % 2 == 0) {
        return ans.next
    } else {
        return ans
    }
};
```