```javascript
function reverseList(head){
let [prev,curren] = [null,head]
while(curren){
    [curren.next,curren,prev]= [prev,curren.next,curren]
}
    return prev
}
```
