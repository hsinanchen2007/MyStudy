```js
var distributeCandies = function(candies, num_people) {
    // 每次递增分发的糖果数量
    let i = 0;
    let index = 0;
    let res = new Array(num_people).fill(0)
    // 剩余糖果数量
    let left = candies
    while(left > 0) {
        i++
        if (index >= num_people) index = 0
            if (left < i) {
                res[index] += left
            } else {
                res[index] += i
            }
        left -= i
        index++
    }
    return res
};
```
