### 解题思路

标题没怎么形容得好，其实主要是看了一下别人的题解大多都是用一个while循环搞定的，这样在l1、l2不等长的时候会增加判断l1或l2是否为null的次数，分成三次while循环是比较好的思路，虽然看起来代码更长，但是思路更加简洁清晰。

另外就是写了一个小小的函数，在创建下一个节点的时候才对上一个节点是否进位进行判断，这样使得代码更短，省掉了一个`carry`变量，不用保存下一个节点是否接收上一个节点的进位的值。

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
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    // 进位函数
    function isCarry(node) {
        if (node.val > 9) {
            node.val -= 10;
            return 1;
        } 
        return 0;
    }

    // 不断迭代的指针节点
    let node = new ListNode(l1.val + l2.val);
    // 最后会返回的头节点
    const resultList = node;
    // l1、l2已经用过了，于是指向下一个元素
    l1 = l1.next;
    l2 = l2.next;

    // l1、l2都有值的时候
    while (l1 && l2) {
        node.next = new ListNode(l1.val + l2.val + isCarry(node));
        node = node.next;
        l1 = l1.next;
        l2 = l2.next;
    }
    // 如果是l1为null、l2不为null，则会直接跳过下面的第一个循环，执行第二个循环；
    // 如果是l2为null、l1不为null，则只会执行下面的第一个循环；
    // 如果是l1、l2同时为null，则下面两个循环都不会执行。
    while (l1) {
        node.next = new ListNode(l1.val + isCarry(node));
        node = node.next;
        l1 = l1.next;
    }
    while (l2) {
        node.next = new ListNode(l2.val + isCarry(node));
        node = node.next;
        l2 = l2.next;
    }

    // 由于carry延迟判断的原因，最后再单独判断一下最后的node需不需要进位
    if(node.val > 9) {
        node.val -= 10;
        node.next = new ListNode(1);
    }
    return resultList;
};
```

### 其他

我的 GitHub [@ceynri](https://github.com/ceynri) 欢迎访问~
