// 解题思路，模仿每一位的加法计算，涉及到进位的问题
// 运用递归，代码清晰简洁，方便理解
var addTwoNumbers = function(l1, l2, carry = 0) {
    // 如果当前位已不需要计算，则返回null
   if(l1 === null && l2 === null && carry == 0) return null
   // 如果当前位能够计算，则将空节点转化为 0 进行计算
   if(l1 === null) l1 = new ListNode(0)
   if(l2 === null) l2 = new ListNode(0)
   let newNode = null,
       newCarry = null
   let newVal = l1.val + l2.val + carry
   if( newVal >= 10 ){
        newNode = new ListNode(newVal % 10)
        newCarry = 1
   }else{
       newNode = new ListNode(newVal)
       newCarry = 0
   }
   newNode.next = addTwoNumbers(l1.next, l2.next, newCarry)
   return newNode
};