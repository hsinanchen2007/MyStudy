暴力将所有和全部求出来

```js
var findMaxAverage = function(nums, k) {
    let len = nums.length;
    let arr = [];
    for(let i = 0; i <= len-k; i++) {
    	let sum = 0;
        for (let j = i; j < k+i; j++) {
            sum += nums[j]
        }
        arr.push(sum);
    }
    return Math.max.apply(Math, arr) / k;
};
```

