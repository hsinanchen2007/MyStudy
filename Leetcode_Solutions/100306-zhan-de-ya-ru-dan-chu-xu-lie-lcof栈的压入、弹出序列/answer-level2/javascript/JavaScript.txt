准备一个辅助栈res.
算法流程：
按顺序依次压入pushed各项item，有以下情况：
1.当item和popped第一项相等时，切割popped第一项。
2.当item和popped第一项不相等时：
   比较res的末项和popped第一项是否相等，相等的话删除res最后一项，切割popped第一项
   将item压入res
```
var validateStackSequences = function(pushed, popped) {
    let res=[];
    pushed.forEach((item)=>{
      if(item===popped[0]){
        popped.splice(0,1);
      }else{
        while(res.length&&res[res.length-1]===popped[0]){
          res.pop()
          popped.splice(0,1)
        }
          res.push(item)
      }
    })
    while(res.length){
      if(res.pop()!==popped.shift()) return false
    }
    return true
};
```


第二种方法将第一种简化
```
var validateStackSequences = function(pushed, popped) {
    //辅助
    let res=[];
    for(let i=0;i<=pushed.length;++i){
        res.push(pushed[i]);
        while(res.length>0 && res[res.length-1]==popped[0]){
            res.pop();
            popped.shift();    
        }
    }
    return popped.length==0;
};
```
