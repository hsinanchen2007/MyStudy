```js
var binaryGap = function(N) {
    let nTo2 = N.toString(2);
    let left = nTo2.indexOf('1');
    let right = nTo2.indexOf('1', left+1);
    let max = 0;
    for (let i = left+1; i < nTo2.length; i++) {
        if (nTo2[i] == 1) {
            max = Math.max(max, right-left)
            left = i;
            right = nTo2.indexOf('1', left+1);
        }
    }
    return max
};
```