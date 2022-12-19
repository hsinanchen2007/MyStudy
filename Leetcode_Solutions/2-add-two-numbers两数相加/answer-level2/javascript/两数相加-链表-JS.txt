/**
 * Definition for singly-linked list.
//  * function ListNode(val) {
//  *     this.val = val;
//  *     this.next = null;
//  * }
 */

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
    //创建一个新链表
    let curr = new ListNode();
    let head = curr;
    let p = l1,q=l2;
    //相加值 和进位判断
    let count = 0,flag = 0;
    //当两条链表没有遍历结束时
    while(p || q){
        //短链表遍历结束，为其创建新的节点，值为0
        if(p === null){
            p = new ListNode();
            p.val = 0;
        } 
        if(q === null){
            q = new ListNode();
            q.val = 0;
        } 
        //两个节点和进位相加结果
        count = p.val + q.val + flag;
        //不需要进位值
        if((count) < 10){
            curr.val = count;
            flag = 0;
        }else{
            //需要进位时
            curr.val = count%10;
            flag = 1;
        }
        p = p.next;
        q = q.next;
        //长链表如果结束，不需要指向下一个节点
        if(p || q ){
            var node = new ListNode();
            curr.next = node;
            curr = curr.next;
        }
        //如果两条链表遍历结束需要进位时
        if( !p && !q && flag ){
            var node = new ListNode(flag);
            curr.next = node;  
        }
        
    }
    return head;
};