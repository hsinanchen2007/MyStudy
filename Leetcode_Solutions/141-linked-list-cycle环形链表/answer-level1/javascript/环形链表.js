1.设计两个指针，一个快指针一个慢指针，就像跑不一样，如果存在环，快指针总会追到慢指针
var hasCycle = function(head) {
     let slow = head, fast = head
     while(fast && fast.next){
          slow = slow.next
          fast = fast.next.next
          if(slow === fast) return true
     }
    return false
}