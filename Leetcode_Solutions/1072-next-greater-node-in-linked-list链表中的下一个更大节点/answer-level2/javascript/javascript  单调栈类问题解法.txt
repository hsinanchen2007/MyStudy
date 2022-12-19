```
var nextLargerNodes = function(head) {
    let stack=[];
    let hash=new Map();
    let temphead = head;
    while(temphead!=null){
            //stack维持的是一个单调递减栈如[5，3，2] 当下一个即将入栈的元素大于前面的元素，该元素就是5，3，2的下一个最大值
        while(stack.length!=0 && stack[stack.length-1].val<temphead.val) {
            hash.set(stack.pop(),temphead.val); 
        }
        stack.push(temphead);
        temphead = temphead.next;
    }
    let res=[];
    while(head!=null){
        if(hash.has(head)) res.push(hash.get(head));  
        else res.push(0); 
        head = head.next;
    }
    return res;
};
```
