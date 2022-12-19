```js
var distributeCandies = function(candies) {
    const size = new Set(candies).size
    if(size >= candies.length / 2) {
        return candies.length / 2
    } else {
        return size
    }
};
```

```js
var distributeCandies = function(candies) {
    return Math.min([...new Set(candies)].length, candies.length/2)
};
```

