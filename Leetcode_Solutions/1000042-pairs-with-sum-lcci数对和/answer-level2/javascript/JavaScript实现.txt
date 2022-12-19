# JavaScript最简单的思路：
+ 从前往后一个一个遍历（不需要排序），找到与每一个元素的和为target的元素，然后插入到数组中，标记用过的元素，标记过的元素不用

```
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */

// 首先排序
// 双指针， 一个往前找，一个往后找
// 如果和相等就插入到数组
// 如果和大于target就end往前移动
// 如果和小于target就start往后移动
var pairSums = function(nums, target) {
    nums.sort((x, y) => x - y)
    var start = 0, end = nums.length-1, result = new Array()
    while (start < end) {
        if (nums[start] + nums[end] === target) {
            result.push(
                [nums[start], nums[end]]
            )
            start++
            end--
        } else if (nums[start] + nums[end] > target) {
            end--
        } else if (nums[start] + nums[end] < target) {
            start ++
        }
    }
    return result
};

// 这段代码没问题，但是运行速度太慢了,换个方式
// var pairSums = function(nums, target) {
//     let filterNums = nums.map(item => {
//         return {
//             val: item,
//             isUsed: false
//         }
//     })
//     let result = []
//     for (var i = 0; i < nums.length; i++) {
//         if (filterNums[i].isUsed === false) {
//             let val = target - nums[i]
//             let index = filterNums.findIndex(item => {
//                 return item.isUsed !== true && item.val === val
//             })
//             if (index !== -1 && index !== i && filterNums[index].isUsed === false) {
//                 result.push([nums[i], nums[index]])
//                 filterNums[i].isUsed = true
//                 filterNums[index].isUsed = true
//             }
//         }
//     }
//     return result
// };
```
