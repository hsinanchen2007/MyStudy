```
var lastRemaining = function(n, m) {
    let arr = [];
    for (let i=0;i<n;i+=1) {
        arr.push(i);
    }
    let anchor = 0;
    while(arr.length > 1) {
        let tem = m + anchor;
        if (tem > arr.length) {
            tem = tem - (arr.length * parseInt((tem-1)/arr.length));
        }
        anchor = tem - 1;
        arr.splice(tem-1,1)
    }
    return arr[0];
};
```


简单非递归方法。明天更新递归方法。