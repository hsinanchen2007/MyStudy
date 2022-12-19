JavaScript
        执行用时 :88 ms, 在所有 JavaScript 提交中击败了81.38%的用户
        内存消耗 :34.5 MB, 在所有 JavaScript 提交中击败了49.51%的用户

使用栈，将开放括号添加到栈中，如果不是开放括号，进行判断之后决定是返回false还是进行出栈操作,最后判断栈是否为空


```
/**
     * @param {string} s
     * @return {boolean}
  */
 var isValid = function(s) {
        var test1 = ["(","{","["];
        var test2 = [")","}","]"];
        var stack = [];
        var arrString = s.split("");
        if(arrString.length==0){return true}
        if(getIndex(arrString[0])==-1){return false}
        
        for(var i=0;i<arrString.length;++i ){
            if(getIndex(arrString[i])>=0){
                stack.push(arrString[i]);
            }else{
                var index = getIndex(stack[stack.length-1]);
                if(test2[index]==arrString[i]){
                    stack.pop()
                }else{
                    return false;
                }
            }
        }
        
        if(stack.length==0){
            return true;
        }else{
            return false;
        }
        function getIndex(str){
            for(var i = 0;i<test1.length;i++){
                if(str==test1[i]){

                    return i;
                }

            }
                return -1;
            
        }
    };

```
   