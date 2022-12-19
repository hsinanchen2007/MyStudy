### 解题思路
![image.png](https://pic.leetcode-cn.com/3bf4caeb8ab351d50ee7cde178728d11bd8f0fa59311cfa4b352efdc325d09c6-image.png)

是不是打开递归的方式不对。。。

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
var reverseList = function (head) {
    // way 2. Try recursion way
    if (!head) return null;
    if (head && !head.next) return head;
    if (head && head.next) {
        let ret = node = reverseList(head.next);
        while (node.next) {
            node = node.next;
        }
        node.next = head;
        head.next = null;

        return ret;
    }
};
```