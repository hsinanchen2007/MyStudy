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
var middleNode = function(head) {
    // 1.使用堆栈方式进行做
    //首先遍历一遍单链表，记录链表的长度len，计算中间节点的位置。 用空间换时间：即开辟一个数据ListNode arr[]，记录所有节点，最后返回arr[len/2]的节点即可； 用时间换空间：再次遍历以便链表，遍历到len/2次时返回当前节点记为中间节点。
    let arr=[]
    let p = head
    while(p!=null) {
        arr.push(p)
        p = p.next
    }
    let start = parseInt(arr.length/2)
    return arr[start]
};