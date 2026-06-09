### 解题思路
打卡！一开始被绕进去了，后来看了一下别人的代码理清了思路
迭代：new一个新的头结点newHead占位，（这里的newHead是新链表中头结点的前一个占位结点）
old:1->2->3->4->5->NULL
newHead->NULL
1)let next = head.next
  1 -> 2 ->3->4->5->NULL
head  next
2)head.next = newHead.next
  newHead->NULL <- 1 |   -/-> 2 ->3->4->5->NULL
                head |       next
3)newHead.next = head
  newHead -/-> NULL   
     |-----> 1 ->NULL|   -/-> 2 ->3->4->5->NULL
            head     |       next
4)head = next
  newHead -/-> NULL   
     |-----> 1 ->NULL|   -/-> 2 ->3->4->5->NULL
             *                ^
            head============next
old: 2 ->3->4->5->NULL
new: newHead -> 1 ->NULL
return newHead.next

递归：先判断是否是空链表或一个结点的链表，是则直接返回head
用next保存当前头结点的下个结点
用newHead取新链表的头指针，用递归一直找到最后一个结点，这个结点就是新链表的头结点
当前结点的下个结点的下个结点指向当前结点，反转链表
当前结点的下个结点指针置NULL，（在上一层递归函数中，这一层的当前结点为上一层的下一结点，此时这一层当前结点的下个结点的指针（这一层为NULL）会指向上一层的当前结点），递归结束，旧链表的头指针的下个结点指向NULL，函数返回newHead（新链表头指针）
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
// 迭代
var reverseList = function(head) {
    // if(head==null||head.next==null){
    //     return head
    // }
    // let newHead = head
    // let pre = null
    // while(newHead){
    //     let next = newHead.next
    //     newHead.next = pre
    //     pre = newHead
    //     newHead = next
    // }
    // return pre
    var newHead = new ListNode(-1)
    while(head!=null){
        let next = head.next
        head.next = newHead.next
        newHead.next = head
        head = next
    }
    return newHead.next
};
// //递归
// var reverseList = function(head) {
//     if(head==null||head.next==null){
//         return head
//     }
//     var next = head.next
//     var newHead = reverseList(next)
//     next.next = head
//     head.next =null
//     return newHead
// };
```