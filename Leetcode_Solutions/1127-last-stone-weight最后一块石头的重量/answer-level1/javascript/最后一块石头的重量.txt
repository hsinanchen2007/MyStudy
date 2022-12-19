```js
var lastStoneWeight = function(stones) {
    while(stones.length > 1) {
    	stones.sort((a, b) => b - a)
    	stone1 = stones.shift()
    	stone2 = stones.shift()
    	if (stone1 !== stone2) {
    		stones.push(stone2-stone1)
    	}
    }
    return stones[0] ? stones[0] : 0
};
```
