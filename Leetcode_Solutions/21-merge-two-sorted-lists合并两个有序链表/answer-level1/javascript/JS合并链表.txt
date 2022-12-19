### 解题思路
创建一个新的节点，用来作为重新组合过的链表的起始点并把变量名l3和temp同时指向这个起始点。 
当l1或l2不是null的时候，比较l1和l2的值，并先后令temp.next和temp指向值较小的结点。通过这样就为较小的这个结点排好了序，为了继续帮下一个结点排序， 要让l1或l2指向这个结点。
l3的指向始终不变， 排序完成，我们通过l3.next就可以依次访问每个节点了。


### 代码

```javascript

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
 *
 */


var mergeTwoLists = function(l1, l2) {
let l3 = new ListNode("head");
let temp = l3;
while (l1!==null||l2!==null){
    if (l1 == null){
        temp.next = l2;
        return l3.next;
    }
     if (l2 == null){
        temp.next = l1;
        return l3.next;
    }

    if (l1.val<l2.val){
        temp.next = l1;
        temp = l1;
        l1 = l1.next;
    }
    else {
        temp.next = l2;
        temp = l2
        l2 = l2.next;
    }
}
return l3.next;
};
```