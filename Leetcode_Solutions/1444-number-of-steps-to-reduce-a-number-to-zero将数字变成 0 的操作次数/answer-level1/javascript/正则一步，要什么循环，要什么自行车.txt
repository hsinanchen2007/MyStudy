```javascript
  var numberOfSteps = function (num) {
    const binStr = num.toString(2);
    const arr = binStr.match(/1/g);
    return arr ? binStr.length + arr.length - 1 : 0;
  };
```
