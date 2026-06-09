```javascript []
var heightChecker = function (heights) {
    let height = Array.from(heights);
    let arr = heights.sort(function (x, y) {
        return x - y
    })
    let times = 0;
    arr.forEach((item, index) => {
        if (arr[index] !== height[index]) { times++ }
    })
    return times
};

console.log(heightChecker([1, 1, 4, 2, 1, 3]))

/**
 * 解题思路： 
 * 
 * 1. 主要是利用的数组排序
 * 2. 排序成功后，对比两个数组的不同之处
 * 3. 即可得出答案
 */
```

