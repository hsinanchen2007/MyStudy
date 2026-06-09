### 解题思路
我也是第一次用js来刷题的。对于这个题，我刚开始也是懵懵的，没有看题上面的注释，就是一顿数组的倒叙操作，结果显示[undefined].嗯嗯嗯。  回过头来，搜了下js链表操作，结果都是先定义一个节点对象，然后再对这个节点对象操作。看下题上面的注释，已经提前说明定义了ListNode 对象，输入的也是ListNode对象。还是要看注释的，注释很重要。所以写的算法也是对输入的ListNode 进行操作，返回ListNode.

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
var reverseList = function(head) {
    var pre = null;
    var curr = head;
    while(curr){
        temp = curr.next;
        curr.next = pre;
        pre = curr;
        curr =temp
    }
    return pre;

};
```