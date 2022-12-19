![21.png](https://pic.leetcode-cn.com/57782ae615533238296a5adbb489f16ad6e5e756c387341ae053daa82029f837-21.png)  

`
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
    if(!l1 && !l2){
        return l1;
    }
    let temp = [];
    while(l1 && l2){
        if(l1.val < l2.val){
            temp.push(l1);
            l1 = l1.next;
        }else{
            temp.push(l2);
            l2 = l2.next;
        }
    }

    if(l1){
        temp.push(l1);
    }
    if(l2){
        temp.push(l2);
    }

    for(let i=0;i<temp.length-1;i++){
        temp[i].next = temp[i+1];
    }
    return temp[0];
};
`
