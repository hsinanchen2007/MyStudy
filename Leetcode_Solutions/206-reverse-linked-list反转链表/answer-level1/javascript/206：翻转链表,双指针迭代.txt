```
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
var pre=null;
var cur=head;
while(cur!=null){
var next=cur.next;
cur.next=pre;
pre=cur;
cur=next;
}
//此时的pre是最后一个数据结点，cur只是空节点
return pre;

};
```
### 也可以利用数组等新空间。递归等方法解题