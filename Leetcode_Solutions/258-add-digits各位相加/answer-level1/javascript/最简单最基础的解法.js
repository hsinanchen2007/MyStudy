本人写了一种最简单，最基础的写法，希望有大神有更好的解法，欢迎指点。
```
/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    var nums = '' + num;
    var add = 0;
    var end = 0;
    for (var i = 0; i < nums.length; i++) {
        add += Number(nums[i]);
    }
    
    add = '' + add;
    for (var i = 0; i < add.length; i++) {
        end += Number(add[i]);
    }
    return end >= 10 ? addDigits(end) : end
};
```
