1、读题要仔细，题目说了是在不改变的A数组的前提下
2、对数组的操作要熟悉，哪些改变原数组，哪些不改变
3、ES6的扩展运算符
```
var merge = function(A, m, B, n) {
    A.splice(m , A.length , ...B)
    
    //对A进行排序
    A.sort(function(a,b){
        if(a>b){
            return 1
        }else{
            return -1
        }
    })
    return A
};
```
