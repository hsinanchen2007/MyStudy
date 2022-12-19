### 代码

```javascript
var sumNums = function(n) {
    n && (n += sumNums(n-1));
    return n
};
```