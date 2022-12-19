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
  let cur = head  //  当前节点
  let prev = null //  前置节点初始化（head节点无前置节点）
  while(cur){
    let temp = cur.next //  保存当前节点的后置节点 之后递归到下一个节点需要
    cur.next = prev
    prev = cur
    cur = temp
  };
  return prev
};
```
审题思路
  大致需要把当前节点的next 换成当前节点的前置节点 提示用递归 

解题过程
  1.第一个节点无前置节点 所以需要声明初始化一个前置节点prev
  2.开始递归 递归结束提交为 当前节点不为null 
  3.先把当前节点后置节点变为当前节点的前置节点
  4.然后把前置prev变为当前节点 因为下一次递归所需
  5.再把当前节点设为后置节点

坑
  3，4，5步骤顺序不能变 有点像插入和删除链表中的某个节点 顺序变了就找不到值了

时间复杂度/空间复杂度
  O（n）/O（1）