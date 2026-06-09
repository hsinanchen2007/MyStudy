```
function ListNode(val) {
      this.val = val;
      this.next = null;
 }
  
var deleteDuplicates = function(head) {
  if(!head || (head && !head.next))return head

  const res = new ListNode(null)
  let p = res
  const map = new Map()
  while(head) {
    const temp = head.next
    if(!map.has(head.val)) {
        map.set(head.val, 1)
        p.next = head
        p = p.next
        p.next = null
    } 
    head = temp
  }
  return res.next
};
```
