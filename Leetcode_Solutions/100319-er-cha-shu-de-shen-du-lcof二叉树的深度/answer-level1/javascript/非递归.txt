额，因为递归相当方便，就想试下非递归
非递归主要问题在于出栈时深度的计算
比如说[1,null,2]左子树为空出栈深度减一，后到右子树深度就不对
我没能想到特别好的解决方法，于是用一个栈来记录深度，这样在出栈时深度也出栈就不会有类似问题了

``` javascript []
var maxDepth = function(root) {
    if(root === null){
        return 0;
    }
    var len=[];
    var stack = [];
    var cur = root;
    var deep = 0,maxDeep = 0;
    do{
        if(cur !== null){
            stack.push(cur);
            cur = cur.left;
            deep++;
            len.push(deep);
        }
        else{
            cur = stack.pop().right;
            deep = len.pop();
        }
        maxDeep = maxDeep > deep ? maxDeep : deep;
    }while(stack.length != 0 || cur !== null)
    return maxDeep;
};
```