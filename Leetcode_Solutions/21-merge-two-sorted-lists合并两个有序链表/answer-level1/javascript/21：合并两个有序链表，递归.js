我们递归实现，最开始我是用for循环，看到递归解题我弱爆了。
- 出口就是其中一个null的时候。
- 归到第一层的时候，return l1 ||return l2返回的就是归并后的链表 
```
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
var mergeTwoLists = function(l1, l2) {
 if(l1==null||l2==null)return l1||l2;
 if(l1.val<l2.val){
     l1.next= mergeTwoLists(l1.next,l2);
     return l1;//层层递归

 }//l2小
 else{
    l2.next = mergeTwoLists(l1, l2.next);
            return l2;
 } 
}
```