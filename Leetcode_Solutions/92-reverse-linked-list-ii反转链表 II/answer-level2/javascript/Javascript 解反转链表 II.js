### 双指针一次遍历反转指定段的链表
这道题是反转链表的进阶题，其实可以简单的将其转换为 反转链表I 来进行求解，思路如下：
1、首先设置一个哑结点，其next指针指向链表的头部。哑结点的作用是即使m = 1时，也不用特殊考虑头结点，这样可以规避代码的分支；
2、从哑结点开始遍历链表，当当前遍历的节点所在的位置与 m 相等时，停止，此时指针应指向需要反转的第一个节点的前一个节点，如下图所示：
**start**
![start.png](https://pic.leetcode-cn.com/f2535552ea39a13a67b179bcde340a751429265d300bdd87ab53fecdc2ac8886-start.png)
**end**
![image.png](https://pic.leetcode-cn.com/92dfe398016db3931d0034cbe7db689696803ed1f407592b96c0d954050c4732-image.png)
3、接下来就是常规的双指针反转链表了，终止条件是反转的次数 大于等于 n - m + 1；

代码如下：
```
var reverseBetween = function(head, m, n) {
    // 如果m === n 则直接返回
    if (m === n) return head;
    let total = n - m + 1;
    let count = 1;
    let length = 1;
    // 设置哑结点
    let newHead = new ListNode();
    newHead.next = head;
    let pre = newHead;
    // 遍历找到要反转的段的前一个节点
    while(length < m) {
        pre = pre.next;
        length++;
    }
    // 如果该节点没有next节点，则直接返回
    if (!pre.next) return newHead.next;
    // 常规双指针反转链表，终止条件是反转次数 大于等于 toatl
    let p = pre.next, q = p.next, pe = p;
    while(count < total) {
        const next = q.next;
        q.next = p;
        pe.next = next;
        p = q;
        q = next;
        count++;
    }
    // 将反转后的链表接上之前的链表
    pre.next = p;
    return newHead.next;
};
```
如有疑问，欢迎指正，谢谢
