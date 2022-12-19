### 解题思路
javascript提供的底层api有很大的帮助，所以可以使用短短的几行代码就可以完成这个用例，
只使用一个for循环，其实这和官方的第一个暴力解题方式很像，其实let sub = nums.indexOf(target - nums[i],i+1)这一句就是一个内层for循环，只不过这个不需要我们编码了，indexof提供了第二个参数，就是从第几个下标开始查找，我使用了i+1就是为了避免返回两个相同的下标，也就是数组中要求的每一个数不能重复使用。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    for(let i =0;i<nums.length;i++){
        let sub = nums.indexOf(target - nums[i],i+1)
        if(sub != -1){
            return [i,sub];
        }
    }
};
```