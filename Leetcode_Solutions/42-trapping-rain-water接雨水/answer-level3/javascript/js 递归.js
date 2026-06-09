寻找最大值还需要优化一下
```js
var trap = function(height) {
    function findMaxHeight(i, j, isLast) {
        if (j < 0) return 0;
        if (i >= j) return j;
        let index = i, max = height[i];
        if(isLast) {
            for(let k = i + 1; k <= j; k++) {
                if (height[k] >= max) {
                    max = height[k];
                    index = k;
                }
            }
        }
        else {
            for(let k = i + 1; k <= j; k++) {
                if (height[k] > max) {
                    max = height[k];
                    index = k;
                }
            }
        }
        return index;
    }
    function half(i, j) {
        if(j - i < 2) return 0;
        const b = findMaxHeight(i, j);
        const a = findMaxHeight(i, b - 1);
        const c = findMaxHeight(b + 1, j, true);
        let sum = 0;
        for(let k = a; k <= c; k++) {
            if (k === b) continue;
            sum += (k < b ? height[a] : height[c]) - height[k];
        }
        return half(i, a) + half(c, j) + sum;
    }
    return half(0, height.length - 1);
};
```
