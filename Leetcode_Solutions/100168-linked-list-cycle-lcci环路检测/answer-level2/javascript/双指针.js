
### 代码

```javascript
var detectCycle = function(head) {
  let fast = head
  let flow = head
  while(fast && fast.next){
    fast = fast.next.next
    flow = flow.next
    if(fast == flow){
      break
    }
  }
  if(!fast || !fast.next) return null
  fast = head
  while(fast != flow){
    fast = fast.next
    flow = flow.next
  }
  return fast
};
```