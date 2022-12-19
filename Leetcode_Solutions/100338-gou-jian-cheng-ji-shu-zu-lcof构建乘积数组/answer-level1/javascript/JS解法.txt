### 代码

```javascript

var constructArr = function(a) {
    let res = [];
    const len = a.length;
    let left = 1;
    for(let i = 0; i < len; i++){
        res[i] = left;
        left *= a[i];
    }
    let right = 1;
    for(let i = len - 1; i >= 0; i--){
        res[i] *= right;
        right *= a[i] 
    }
    return res
};
```