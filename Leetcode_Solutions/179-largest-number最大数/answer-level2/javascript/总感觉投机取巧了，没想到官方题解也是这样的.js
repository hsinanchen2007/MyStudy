```
/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
     nums.sort((a, b) => {
            let t1 = a + '' + b
            let t2 = b + '' + a
            if(t1 < t2) return 1
            else if(t1 > t2) return -1
            else return 0
        })
    const ans = nums.join('')
    return parseInt(ans) === 0 ? '0' : ans
};
```
