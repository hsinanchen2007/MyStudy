### 解题思路
将链表转换成数组，删除倒数n位后，再转换成链表返回

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
 * @param {number} n
 * @return {ListNode}
 */
var removeNthFromEnd = function(head, n) {
    //把链表转化为数组
    function toNum(head){
        var arr=[]
        while(head){
            arr.push(head.val)
            head = head.next
        }
        return arr
    }
     //删除数组第倒数n项
    var a = toNum(head)
    a.splice(a.length-n,1)
    //数组转化为链表返回
    var node = {
        val: null,
        next: null
    },
        head = node
    for (var i = 0; i < a.length; i++) {
        node.next = {
            val: a[i],
            next: null
        }
        node = node.next
    }
    return head.next
};



```