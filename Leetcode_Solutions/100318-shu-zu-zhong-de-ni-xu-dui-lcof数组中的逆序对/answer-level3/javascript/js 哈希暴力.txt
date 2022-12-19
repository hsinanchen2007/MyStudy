想不出其他思路了。。。
```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var reversePairs = function(nums) {
    let res = 0, temp, j;
    const record = [0];
    const repeat = {};
    repeat[nums[0]] = 0;
    for(let i = 1; i < nums.length; i++) {
        repeat[nums[i]] = repeat[nums[i]] !== undefined ? repeat[nums[i]] + 1 : 0;
        temp = 0;
        j = i;
        while(j--) {
            if (nums[j] === nums[i]) {
                temp += record[j];
                break;
            }
            if (nums[j] === nums[i] + 1) {
                temp += (record[j] + 1) + repeat[nums[j]];
                break;
            }
            if (nums[i] < nums[j]) temp++;
        }
        record[i] = temp;
        res += temp;
    }
    return res;
};
```
