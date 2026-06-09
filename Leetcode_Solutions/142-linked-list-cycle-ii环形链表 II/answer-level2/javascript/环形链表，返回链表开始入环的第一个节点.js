### 解题思路


图解
![image.png](https://pic.leetcode-cn.com/62f9b04f96014980aab4bfb6216bacebd3d3c952d84e5be067fead2dda934067-image.png)


![image.png](https://pic.leetcode-cn.com/f376d5eeb62ca97ded685f6af2588fe5d2de62838c5dff0d5f1cd71dc0641647-image.png)

作者：Alexer-660
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/142-huan-xing-lian-biao-ii-by-alexer-660/


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
 * 还可以用数组判重的方式解决，https://github.com/giscafer/leetcode-js/tree/master/src/data-structures/linked-list
 * @param {ListNode} head
 * @return {ListNode}
 */
var interset = function (head) {
    // 空链表 || 单节点链表
    if (head == null || head.next === null) {
        return null;
    }

    // 快慢指针
    let slow = head;
    let fast = head;
    while (fast !== null && fast.next !== null) {
        slow = slow.next;
        fast = fast.next.next;
        if (fast == slow) {
            return slow;
        }
    }
    return null;
};

var detectCycle = function (head) {
    let intep = interset(head);
    if (intep === null) { // 没有环
        return null;
    }
    let start = head;
    while (start !== intep) {
        start = start.next;
        intep = intep.next;
    }
    return start;
};

```

## 总结

关于链表数据结构笔记：[https://github.com/giscafer/leetcode-js/tree/master/src/data-structures/linked-list](https://github.com/giscafer/leetcode-js/tree/master/src/data-structures/linked-list)

![fe-insights.jpg](https://pic.leetcode-cn.com/936dcb02e5f5636a779abf809514677985a18b20667952e608527e2026f1c3a2-fe-insights.jpg)
