### 代码

```javascript
var plusOne = function(digits) {
    const num = BigInt(digits.join('')) + BigInt(1)
    return String(num).split('')
};
```