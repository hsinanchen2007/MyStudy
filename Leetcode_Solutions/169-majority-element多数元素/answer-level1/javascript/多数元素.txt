1、暴力破解

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
   let len = nums.length / 2;
   for(let i = 0 ; i < nums.length; i++) {
       let count = 0;
       for(let j = 0 ; j < nums.length; j++) {
           if(nums[i] === nums[j]) {
               count ++
           }
       }
       if(count > len) {
           return nums[i];
       }
   }
};
```
时间复杂度：O(n^2)暴力算法包含两重嵌套的 for 循环，每一层 n次迭代，所以总的是平方级的时间复杂度。
空间复杂度：O(1) 暴力方法没有分配任何与输入规模成比例的额外的空间

2、哈希法
```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let map = new Map();
    if(nums.length <= 1) return nums[0];// 需要单独处理为一个元素的情况  
    for(const num of nums) {
        if(map.has(num)) {
            map.set(num,map.get(num)+1)
            if(map.get(num) >= Math.ceil(nums.length/2)) return num;
        } else {
            map.set(num,1)
        }
    }
};
```
时间复杂度：O(n)我们将 nums 迭代一次，哈希表的插入是常数时间的。所以总时间复杂度为 O(n)时间的。
空间复杂度：O(n)