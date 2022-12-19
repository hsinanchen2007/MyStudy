发现不少小伙伴都使用栈来处理这个问题, 题目中只有正数在负数左边的时候才会产生碰撞.

所以在循环当前数组时, 只有asteroids[i] > 0 && asteroids[i+1] < 0, 然后根据两个值的和情况做处理
 1. 大于0,删除负数项, 继续从改正数开始循环
 2. 等于0, 同时删除负数和正数, 从正数前一位开始(没有则是索引0)
 3. 小于0,, 删除正数, 从正数前一位开始循环(没有则索引为0, 负数为首项)

时间复杂度应该是O(n)

```javascript
var asteroidCollision = function(asteroids) {
    for (var i = 0; i <asteroids.length - 1; i++) {
        if (asteroids[i] > 0 && asteroids[i+1] < 0) {
            var r = asteroids[i] + asteroids[i+1];
            if (r > 0) { asteroids.splice(i+1, 1); --i; }
            if (r == 0) { asteroids.splice(i, 2); i = Math.max(i-2, -1); }
            if (r < 0) { asteroids.splice(i, 1); i = Math.max(i-2, -1); } 
	}
    }
    return asteroids 
};
```
