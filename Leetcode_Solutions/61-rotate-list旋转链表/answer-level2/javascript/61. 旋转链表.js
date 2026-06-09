// ## 题目剖析

// 题目是 **旋转链表**，首先我们来看看官方提供的示例：

// 示例1:
// ```
输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
// ```
// 示例2:
// ```
输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL
// ```

// 不难发现，当 ``k`` 为确定的数值时，只要将第 ``len - (k % len)`` 个节点与它的 **上一个节点** 断开，并将 **最后一个节点** 连接到头节点，那么就意味着链表旋转成功。（其中 ``len`` 为链表长度）

// ## 梳理逻辑

// 我们把上面提到的逻辑重新梳理如下👇

// - 找到 **最后一个节点**
// - 找到链表的长度(``len``)
// - 将第 ``len - (k % len)`` 个节点与它的 **上一个节点** 断开
// - 将 **最后一个节点** 跟原来的 **头节点** 连接
// - 旋转成功

// ``tips``: 注意处理链表的边界条件

// ## 示例代码

// ```javascript
/**
 * @param {ListNode} head
 * @param {number} k
 * @return {ListNode}
 */
var rotateRight = function(head, k) {
    let target = head, last = null, len = 1
    while (target && target.next) {
        target = target.next
        len++
    }
    last = target
    target = head
    if (k % len === 0) {
        return head
    }
    let diff = len - (k % len)
    let pre = null
    while (target && diff--) {
        pre = target
        target = target.next
    }
    pre.next = null
    last.next = head
    return target
};
// ```