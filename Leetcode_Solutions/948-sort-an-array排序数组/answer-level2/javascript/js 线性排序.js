### 解题思路
使用一个hash数组存储，将nums中的值作为下标，数组存的值为该数出现的次数，然后遍历这个hash数组就可以了，注意判断一下负数的可能性

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
//   let n = nums.length
//   if(n<=1) return nums
//   let middle = Math.floor(n/2)
//   let index = nums.splice(middle,1)[0]
//   let leftArr = []
//   let rightArr  = []
//   for(let i = 0;i<nums.length;i++) {
//       if(nums[i]<index) {
//           leftArr.push(nums[i])
//       } else {
//           rightArr.push(nums[i])
//       }
//   }
//   return sortArray(leftArr).concat(index,sortArray(rightArr))
     let result = []
     let hash = new Array(10000000).fill(0)
     for(let num of nums) {
         hash[num+50000]++
     }
     for(let i = 0;i<hash.length;i++) {
         while(hash[i]>0) {
             hash[i]--
             result.push(i-50000)
         }
     }
     return result
};
```