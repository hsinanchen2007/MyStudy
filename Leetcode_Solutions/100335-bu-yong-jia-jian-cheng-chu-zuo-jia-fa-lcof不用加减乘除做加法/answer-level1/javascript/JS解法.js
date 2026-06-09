### 代码

```javascript
var add = function(a, b) {
    while(a !== 0){
        let temp = (a ^ b);
        a = (a & b) << 1;
        b = temp;
    }
    return b
};

```