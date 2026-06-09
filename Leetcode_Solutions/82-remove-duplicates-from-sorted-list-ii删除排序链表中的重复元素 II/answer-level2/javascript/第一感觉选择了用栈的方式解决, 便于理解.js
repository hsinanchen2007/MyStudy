**遇见一个新值入栈, 再遇见和新值一样的,就出栈, 最后栈中就不会出现重复的值**

```
var deleteDuplicates = function(head) {
    let dummyHead = { next: null };
    let curr = dummyHead;

    let first = { val : null };
    let stack = [];
    while (head) {
        let next = head.next;
        if (first.val != head.val ) {
            head.next = null;
            first = head;
            stack.push(first);
        } else {
            if (stack.length) {
                if (stack[stack.length - 1].val == head.val) {
                    stack.pop();
                }
            };
        };
        head = next;
    };

    while (stack.length) {
        let h = stack.shift();
        curr.next = h;
        curr = curr.next;
    }
    console.log(require('util').inspect(dummyHead.next, false , null, true)); 
    return dummyHead.next;
};

```
