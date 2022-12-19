### 解题思路
示例的输出有一点误导性
可以这样理解链表的反转:
输入：1->2->3->4->5->NULL
输出：NULL<-1<-2<-3<-4<-5
可见反转链表的实质，就是把原本：前一项(pre)指向当前项(current)，转换成：当前项(current)指向前一项(pre)

例如：1->2
1的pre是null，current是1，现在需要让1指向null，即current指向pre，所以只需要设置current项(即1)的next属性为pre项(即null)就行

同理：1->2->3
current项是2，pre项是1，原本1->2，现在要求1<-2，所以只需要设置2的next属性为1就行

总结：
第一个pre项肯定是null
第一个current项是1
设置current.next = pre即可反转链表

为了能够循环执行，下一个pre应该是现在的current
而下一个current应该是没有反转前的current.next

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
// 1->2->3->4->5->NULL
// NULL<-1<-2<-3<-4<-5
var reverseList = function(head) {
    let pre = null, current = head
    while(current){
        let next = current.next
        current.next = pre
        pre = current
        current = next
    }
    return pre
};
```