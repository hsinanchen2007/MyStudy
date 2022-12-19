[点我看原题](https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)  
[点我看原文](https://juejin.im/post/5e4c96a4e51d4526e651b897)

## 题目描述

输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

### 示例

**输入：** 1->2->4, 1->3->4  
**输出：** 1->1->2->3->4->4

## 解题思路

1. 循环比较两个链表，较小的节先插入新链表中，直至两个链表为空；
2. 递归比较两个链表，逻辑同上。


![](https://pic.leetcode-cn.com/5ac8429ee53bd609843f29d101288176338b5796688bca6f55c803ff1562b37e-file_1582085848221)

## 示例代码

### 循环比较

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    // 定义新链表
    let head = new ListNode()
    let list = head
    // 循环比对大小
    while (l1 && l2) {
        let val = 0
        if (l1.val <= l2.val) {
            val = l1.val
            l1 = l1.next
        } else {
            val = l2.val
            l2 = l2.next
        }
        list.next = new ListNode(val)
        list = list.next
    }
    list.next = l1 || l2
    // 返回合并后的新链表
    return head.next
};
```

### 递归比较

```javascript
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    if (!l1 && !l2) {
        return null
    }
    if (l1 && !l2) {
        return l1
    }
    if (!l1 && l2) {
        return l2
    }
    let node = new ListNode()
    if (l1.val <= l2.val) {
        node.val = l1.val
        node.next = mergeTwoLists(l1.next, l2)
    } else {
        node.val = l2.val
        node.next = mergeTwoLists(l1, l2.next)
    }
    return node
};
```