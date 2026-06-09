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
 * 思路：将链表转为数组，用数组排序，排序后重建链表
 */
var sortList = function(head) {
  if(head === null || head.next === null){
      return head;
  }
  var cur = head;
  var index = 0;
  var arr = [];
  while(cur !== null){
      arr[index] = cur.val;
      cur = cur.next;
      index += 1;
  }
  arr.sort((a, b) => a - b);
  cur = head;
  index = 0;
  while(cur !== null){
      cur.val = arr[index];
      index += 1;
      cur = cur.next;
  }
  return head;
};

