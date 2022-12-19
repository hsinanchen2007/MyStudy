### 解题思路
1. 1个数组用来存一组节点，unshift反向推入
2. 完成一组反转之后用另一个大数组连接起来
3. 最后那个数组reverse反转之后再用大数组连接起来
4. 大数组按顺序迭代生成结果链表

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
 * @param {number} k
 * @return {ListNode}
 */
var reverseKGroup = function(head, k) {
    let p = head, arr = [], resultArr = [], index = 0
    if (k < 2) {
        return head
    }
    while (p) {
        arr.unshift(p)
        p = p.next
        if (++index === k) {
            resultArr = resultArr.concat(arr)
            index = 0
            arr = []
        } else if (!p) {
            resultArr = resultArr.concat(arr.reverse())
        }
    }
    resultArr.forEach((item, index) => {
        item.next = resultArr[index+1] || null
    })
    return resultArr[0] || head
}
```