### 利用两次循环找到每个位置需要等待的天数
```js
var dailyTemperatures = function(T) {
    for(var i=0,len = T.length;i<len;i++){
        var temp = T[i]
        var count = 0
        for(var j=i+1;j<len;j++){
            if(T[j] > temp){
                count = j - i
                break
            }
        }
        T[i] = count // 直接将对应位置赋值为天数这样可以节省空间
    }
    return T
};
```
 ### 利用栈

```js
function dailyTemperatures(T) {
    var stack = []
    for(var i=0,len = T.length;i<len;i++){
        var temp = T[i]
        while(stack.length && temp > T[stack[stack.length - 1]]){
            var top =  stack.pop()
            T[top] = i - top
        }
        stack.push(i)
    }
    while(stack.length){
        T[stack.pop()] = 0
    }
    return T
}
```