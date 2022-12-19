js 暴力13行
```js
var validateStackSequences = function(pushed, popped) {
    const stask = [];
    let popHead = 0, j;
    for(let i = 0; i < pushed.length; i++) {
        if(pushed[i] !== popped[popHead]) stask.push(pushed[i]);
        else popHead++;
        j = stask.length - 1;
        while(j >=0 && stask[j] === popped[popHead]) {
            j--;
            popHead++;
        }
        stask.splice(j + 1);
    }
    return popHead === pushed.length;
};
```
