### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
// 和两数之和的思路及其相似，只不过有大于小于0，变成差值绝对值的比较
/*  obj = {
     isFinish: 是否可以提前结束
     target: 目标值；
     min：当前最接近于target的三数之和
     gap：当前与target最小的差值
 } */
var twoNum = function (nums, k, obj) {
   const len = nums.length;
   const target = obj.target;
   let minGap = obj.gap;
   let i = 0;
   let j = len - 1;
   while (i < j) {
     const sum = nums[i] + nums[j] + k;
     const gap = sum - target;
     const sumAbs = Math.abs(gap);
     // console.log(sumAbs, sum, nums[i], nums[j], k)
     if (sumAbs < minGap) {
        // console.log(sum, sumAbs, minGap)
        obj.min = sum;
        obj.gap = sumAbs;
        minGap = sumAbs;
        // 如果等于0，那就可以提前结束
        if (sumAbs === 0) {
            obj.isFinish = true; 
            break;
        }
     }
     // 小于零，说明负数太大，需要向右靠
     if (gap < 0) {
         i++;
     // 反之向左
     } else if (gap > 0) {
         j--;
     }
   }
};

// 思路和三数之和及其相似，但是因为只存在唯一解，所以不存在去重那么多的逻辑，如果等于0，那就可以提前结束
var threeSumClosest = function(sortNums, target) {
   const len = sortNums.length;
   if (len <=3) {
     return sortNums.reduce((pre, cur) => pre + cur, 0);
   }
   const nums = sortNums.sort((a, b) => a-b);
   let res = {
       min: Number.MAX_SAFE_INTEGER,
       gap: Number.MAX_SAFE_INTEGER,
       target: target
   };
   let last;
   // console.log(nums);
   for (let i=0; i<len - 2; i++) {
     twoNum(nums.slice(i + 1), nums[i], res);
     if (res.isFinish) {
         break;
     }
   }
   return res.min; 
};
```