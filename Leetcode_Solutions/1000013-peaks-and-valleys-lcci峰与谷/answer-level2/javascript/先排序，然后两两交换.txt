### 解题思路
先排序，按照从大到小。这时第一个是峰，从第二个开始间隔1个，依次和后面的替换。
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var wiggleSort = function(nums) {
    nums.sort(sortfunction);
    let temp;
    for(let i = 1; i < nums.length-1; i+=2) {
        temp = nums[i];
        nums[i] = nums[i+1];
        nums[i+1] = temp;
    }
};

let sortfunction = function(a, b) {
    return b - a;
}
```