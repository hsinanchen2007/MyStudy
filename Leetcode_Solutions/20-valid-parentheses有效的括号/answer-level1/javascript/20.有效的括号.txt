```javascript
//减少if
const mapping = {
    "(": ")",
    "[": "]",
    "{": "}"
}
var isValid = function(s) {
    //1.优化 奇数取消
    if(s.length%2 !=0)return false;
    
    let stack = [];
    for(let i =0;i<s.length;i++){
        let value = s[i]
        let lvalue = mapping[value];
        if(lvalue){
            //2.1 如果为左元素,入栈
            stack.push(lvalue);
        }else{
            //2.1 如果为右元素,出栈
            if(value != stack.pop()) return false;
        }
    }
    return stack.length == 0;
    // 习惯使用以下方式处理,提供作用域与value
    // let flag = Array.from(s).every((value)=>{
    //     let lvalue = mapping[value];
    //     if(lvalue){
    //         //2.1 如果为左元素,入栈
    //         stack.push(lvalue);
    //     }else{
    //         //2.1 如果为右元素,出栈
    //         if(value != stack.pop()) return false;
    //     }
    //     return true;
    // })
    // //栈必须为空
    // return flag && stack.length == 0;
};
```
