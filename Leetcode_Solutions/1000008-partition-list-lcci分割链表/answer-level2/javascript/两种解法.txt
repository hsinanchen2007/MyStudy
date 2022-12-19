```javascript
var partition = function(head, x) {
  // let t = head
  // let arr = []
  // while(t){
  //   arr.push(t.val)
  //   t = t.next
  // }
  // arr.sort((a,b)=>b-a)
  // let n = head
  // while(n){
  //   n.val = arr.pop()
  //   n = n.next
  // }
  // return head

  let m = a = new ListNode()
  let n = b = new ListNode()
  while(head){
    if(head.val < x){
      a.next = head
      a = a.next
    }else{
      b.next = head
      b = b.next
    }
    head = head.next
  }
  a.next = n.next
  b.next = null
  return m.next
};