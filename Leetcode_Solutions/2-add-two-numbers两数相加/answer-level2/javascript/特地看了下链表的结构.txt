```js
var addTwoNumbers = function(l1, l2) {
    let l = {
        val: 0,
        next: null
    }
    
    let next1 = l1
    let next2 = l2
    let next = l
    for (;;) {
        const v1 = next1 ? next1.val : 0;
        const v2 = next2 ? next2.val : 0;
        let sum = v1 + v2 + next.val
        
        let isReamin= false
        if (sum >= 10) {
            sum = sum - 10
            isReamin = true
        }
        
        next.val = sum

        next1 = next1 ? next1.next : null;
        next2 = next2 ? next2.next : null;
        if (next1 || next2 || isReamin) {
            next = next.next = {
                val: isReamin ? 1 : 0,
                next: null
            }
        } else {
            break
        }
    }
   
    return l
};
```