js 非递归
```
var numberOfSteps  = function(num) {
    let i = 0;
    while(num) {
        if(num % 2) num--;
        else num = num >> 1;
        i++;
    }
    return i;
};
```
