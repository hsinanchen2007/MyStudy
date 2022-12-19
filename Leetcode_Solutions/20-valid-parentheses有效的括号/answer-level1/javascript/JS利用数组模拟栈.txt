作为一个前端渣渣，尽可能的简单处理问题。

```
    //首先建立两个数组用来映射括号，就不整map这么高级了
    let left = ["(","[","{"]
    let right = [")","]","}"]
    
    //再准备一个数组作为中间缓存（可以理解为栈的作用）
    let stack = []
    let sarr = s.split('')

    for(var i=0;i<sarr.length;i++){
        //判断左右括号
        if(left.indexOf(sarr[i])!=-1){
            //如果是左括号，直接存为对应的右括号，方便后面判断
            stack.push(right[left.indexOf(sarr[i])])
        }else {
            //如果是右括号，则与stack数组（栈）中最后一个元素进行对比
            if(stack[stack.length-1]==sarr[i]){
                //相同则抵消
                stack.splice(stack.length-1,1)
            }else {
                //不同直接返回false
                return false
            }
        }
    }
    //最后判断stack数组（栈）的长度
    if(stack.length == 0){
        return true
    }else {
        return false 
    }
```
