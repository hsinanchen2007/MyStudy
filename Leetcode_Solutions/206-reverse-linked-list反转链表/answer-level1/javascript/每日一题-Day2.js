### 解题思路
两种解题思路：递归、迭代

我使用递归的总体思路：

- 假设前n-1步都以完成，我只需要做最后一步
- 处理边界情况，就是对第1步的处理

针对本题：1->2->3->4->5->NULL，则：

- 假设链表状态已经调整为：1-> 2<-3<-4<-5，最后一步是让2指向1，1指向NULL
- 边界情况为：当前节点为5（next节点为null的节点），此时直接返回5即可

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
    if(head==null || head.next==null) return head;
    return helper(head)
};
function helper(head){
    if(head.next==null) return head;
    let new_head=helper(head.next)
    head.next.next=head
    head.next=null;
    return new_head;
}
```