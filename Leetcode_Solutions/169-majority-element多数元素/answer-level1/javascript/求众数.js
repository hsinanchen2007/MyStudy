*法一*

```js
var majorityElement = function(nums) {
    var len = nums.length;
    var obj = {};
    for (let i = 0; i < len; i++) {
        if(obj[nums[i]]) {
            obj[nums[i]]++
        } else {
            obj[nums[i]] = 1
        }
    }
    for(let k in obj) {
        if (obj[k] > len/2) {
            return k
        }
    }
};

var nums = [1,1,1,2,2];
console.log(majorityElement(nums))
```

*法二*

定义一个计数器，循环一次数组，如果循环到的数是众数(假定第一个数是众数)，那么计数器+1，否则-1，当计数器为0的时候，将下一个数作为众数。由于题目对于众数的定义是大于n/2，那么最后计数器肯定大于等于1，一定可以把众数找出来。

```js
var majorityElement2 = function(nums) {
    let count = 0
    let result = 0
    nums.forEach(item => {
        if (count === 0) result = item
        if (result !== item) count--
        if (result === item) count++
    })
    return result
};
```

