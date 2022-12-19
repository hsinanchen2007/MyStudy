splice插入
```js
/**
 * @param {number[]} stones
 * @return {number}
 */
var lastStoneWeight = function(stones) {
    stones.sort((a, b) => a - b);
    let a, b, c, i;
    while(stones.length > 1) {
        a = stones.pop();
        b = stones.pop();
        c = a - b;
        if(!c) continue;
        i = 0;
        while(c > stones[i]) i++;
        stones.splice(i, 0, c);
    }
    return stones.length ? stones[0] : 0;
};
```
