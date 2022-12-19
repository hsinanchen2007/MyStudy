### 解题思路
利用数组的反转函数，先将链表中的数据全部存入到数组中，接着使用reverse函数，最后再重新存储到链表中即可。

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
var reverseList = function(head) {
    let temp = head,
        result = []
    while (temp != null) {
        result.push(temp.val)
        temp = temp.next
    }
    temp = head, i = 0
    result.reverse()
    while (temp != null) {
        temp.val = result[i++]
        temp = temp.next
    }
    return head;
};
```