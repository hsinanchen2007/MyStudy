利用lastIndexOf 和indexOf 获取排序后数组 两个相同值的差别 得到出现次数 再进行数组判断

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    if(nums.length == 1 ) return nums[0]
    let half_length  = Math.ceil(nums.length/2);
    let sortNums = nums.sort();
    for(let item of sortNums){
        if((nums.lastIndexOf(item) - nums.indexOf(item)) + 1 >= half_length ){
            return item;
        }
    }
};
```
