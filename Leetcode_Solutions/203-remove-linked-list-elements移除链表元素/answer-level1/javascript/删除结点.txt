### 解题思路
在链表前插入一个空节点
![image.png](https://pic.leetcode-cn.com/0ce2244db6636cf4e7ac79ff2880881a8fa4f23965fd7d708b408cb7e31491fd-image.png)


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
 * @param {number} val
 * @return {ListNode}
 */
var removeElements = function(head, val) {
    var newHead = new ListNode(null);
    var prev = newHead;
    var cur=head;
    newHead.next=head;
    while (cur){
        if(cur.val!=val){
            prev=cur;
            cur=cur.next;
        }else{
            prev.next=cur.next;
            cur=cur.next;
        }
    }
    return newHead.next;//不能使用head，为什么？
};
