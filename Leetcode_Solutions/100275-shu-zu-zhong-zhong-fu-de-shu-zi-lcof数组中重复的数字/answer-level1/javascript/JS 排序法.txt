1. 排序对比
```js
 var findRepeatNumber = function (nums) {
   nums.sort((a, b) => a - b)
   for (let i = 0; i < nums.length-1; i++) {
     if (nums[i + 1] === nums[i]) return nums[i]
   }
   return -1
 }
```
2. 利用 set
```js
 var findRepeatNumber = function (nums) {
   const set = new Set()
   for (let i = 0; i < nums.length; i++) {
     if (set.has(nums[i])) return nums[i]
     set.add(nums[i])
   }
   return 0
 }
```