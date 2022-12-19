### 解题思路
JavaScript题解

### 代码
非递归版本

```javascript
var reverseList = function (head) {
    let pre = new ListNode(0)
    while (head) {
        let next = head.next;
        [head.next, pre.next, head] = [pre.next, head, next];
    }
    return pre.next
};
```
递归版本

```javascript
var reverseList = function (head) {
    // 利用头结点result,合并head为空的情况
    let result = new ListNode(0);
    let pre = result;
    let reverseNode = function (pre, head) {
        if (!head) return // 终止条件
        let next = head.next;
        [head.next, pre.next, head] = [pre.next, head, next]
        return reverseNode(pre, head)
    }
    reverseNode(pre, head)
    return result.next
};
```
