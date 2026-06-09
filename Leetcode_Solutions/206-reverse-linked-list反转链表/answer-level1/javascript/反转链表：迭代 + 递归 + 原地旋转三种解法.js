### 解题思路
![image.png](https://pic.leetcode-cn.com/20ef57a4611531071184e441a133fa5f4fceaa2b8b482304afdcc7111156a3c3-image.png)

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
// 迭代法
var reverseListIter = function(head) {
    if (!head) {
        return null;
    }
    let node = {};
    while(head) {
        node.val = head.val;
        node = {
            next: node
        }
        head = head.next;
    }
    return node.next;
};

// 递归
var reverseListDps = function(head) {
    if (!head) {
        return null;
    }

    function dps(node, nw) {
        if (!node) {
            return nw;
        }
        return dps(node.next, {
            val: node.val,
            next: nw
        })
    }
    return dps(head, null);
};

// 原地旋转，思想很简单：
// 每次反转一个，然后将反转的看成一个整体，加到下一个链表的尾巴上；
// 比如：
// 1： 1 -> null: 看成一个整体
// 2:  2 -> 1 -> null； 将上面这个整体，设置成2的next;
// 3： 同理往后依次走

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