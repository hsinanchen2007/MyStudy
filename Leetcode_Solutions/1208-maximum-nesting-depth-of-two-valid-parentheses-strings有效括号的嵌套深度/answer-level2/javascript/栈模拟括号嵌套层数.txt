```
var maxDepthAfterSplit = function(seq) {
    var stack=[];
    var depth=0;
    for(var i=0;i<seq.length;i++){
        if(seq[i]=='('){
            depth++;
            stack.push(depth%2);
        }else{
            stack.push(depth%2);
            depth--;
        }
    }
    return stack;
};
```
