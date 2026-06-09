// 遇到问题我们首先要先搞清楚问题到底是什么，然后再想办法解决。对于 **链表** 的问题其实大部分都不算难，写代码之前最好动动笔在纸上画一下，思路便会清晰很多。

// ## 题目剖析

// 题目中描述这样一个结构的链表：

// ```javascript
function Node(val,prev,next,child) {
    this.val = val;
    this.prev = prev;
    this.next = next;
    this.child = child;
}
// ```
// 所以这不仅仅是一个 **双向** 链表，同时它还可能存在 **子链表**  

// 我们再来看看官方提供的输入输出例子👇

// **输入**：
// ```javascript
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL
// ```
// **输出:**
// ```javascript
1-2-3-7-8-11-12-9-10-4-5-6-NULL
// ```

// 扁平化的步骤可以看成这样：

// 第一步：
// ```javascript
 1---2---3---4---5---6--NULL
         |
         7---8---11---12---9---10--NULL
// ```
// 第二步：
// ```javascript
1---2---3---7---8---11---12---9---10---4---5---6--NULL
// ```

// 显然，我们需要递归处理 **子链表**，再把它跟 **父链表** 拼接在一起。

// ## 梳理逻辑

// 分析完题目之后我们来梳理下逻辑👇

// - 找到 **子链表** 并且把它拼接到 **父链表** 的 **下一个节点** 上
// - 如果 存在 **子子链表**，那么先处理 **子子链表**

// 拼接的逻辑可以更加细化，如下👇

// - 保存 **子链表** 的 **第一个节点**
// - 保存 **子链表** 的 **前一个节点** 和这个节点的 **下一个节点**
// - 保存 **子链表** 的 **最后一个节点**
// - 有了 **子链表** 的 **首尾节点** 和 **前后节点**， 就可以把 **子链表** 拼接到 **父链表** 上


// ## 示例代码

// ```javascript
/**
 * @param {Node} head
 * @return {Node}
 */
var flatten = function(head) {
    dfs(head)
    function dfs (head) {
        let target = head, pre = null, last = null
        while (target) {
            let next = target.next, child = target.child
            if (child) {
                target.next = child
                child.prev = target
                target.next = child
                last = dfs(child)
                last.next = next
                pre = last
                target.child = null
                if (next) {
                    next.prev = last
                }
            } else {
                pre = target
            }
            target = next
        }
        return pre
    }
    return head
};
// ```

// 当然这里有个需要注意的地方，``next`` 、 ``prev`` 和 ``child`` 指针都可能是空的，写代码的时候需要把这些情况都考虑进去。