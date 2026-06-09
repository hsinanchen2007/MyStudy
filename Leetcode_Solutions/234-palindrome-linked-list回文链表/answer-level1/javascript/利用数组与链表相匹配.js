/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} head
 * @return {boolean}
 */
var isPalindrome = function(head) {
    let count = 0;//计算长度
    let flag = head;
    let arr = new Array();//new一个数组
    let point;//找出分割点位置
    while(flag){
        count++;
        flag = flag.next;
    }
    for(var i=0;i<parseInt(count/2);i++){
        arr.push(head.val);
        head = head.next;
    }推入数组
    if(count%2!==0){
        head = head.next;
    }//判断是否为偶数
    point = parseInt(count/2)-1;
    while(head){
        if(arr[point]!==head.val) return false;
        point--;
        head = head.next;
    }//进行比较
    return true;
};