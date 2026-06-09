### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
// 这里用到了双指针，而不是单纯的轮询
var twoNum = function (nums, k) {
   const len = nums.length;
   const res = [];
   let i = 0;
   let j = len - 1;
   // 标志位
   let dir;
   while (i < j) {
     // 这也是一个防重复设计
     if (dir && nums[i] === nums[i - 1]) {
         i++;
         continue;
     }
     if (dir === false && nums[j] === nums[j + 1]) {
         j--;
         continue;
     }
     const sum = nums[i] + nums[j] + k;
     // 如果三数之和小于0，说明正数太小或负数太大，因为正数是从最大数递减下来的，所以这里只能将负数变大
     // 即向正数方向靠近，也就是i变大；
     if (sum < 0) {
         i++;
         dir = true;
     // 同上面思路，可得出sum>0时，j向负数靠近
     } else if (sum > 0) {
         j--;
         dir = false;
     } else {
         // 等于0，想要的结果
         res.push([k, nums[i], nums[j]]);
         i++;
         dir = true;
     }
   }
    return res;
};

// 三数之和，最终还是归于了两树之和
var threeSum = function(sortNums) {
   const len = sortNums.length;
   // 第一步肯定是排序，这样便于后续的查询中断，提前结束查找
   const nums = sortNums.sort((a, b) => a-b);
   let res = [];
   let last;
   // console.log(nums);
   // -2的意义就是，-a = b + c，即给b，c留下位置
   for (let i=0; i<len - 2; i++) {
     // 如果nums[i] > 0，那么nums[k > i]就肯定大于0了，排了序的，那就可以提前中断查找了
     if (nums[i] > 0) {
         break;
     }
     // 这是一个防重的设计，因为题目要求不含重复的三元组，后面就不用再做过滤了；
     if (nums[i] === last) {
         continue;
     }

     // 这才是真正的起点，三数之后，最终转化成了求解两数之和，只不过和不为0，而是-nums[i]
     last = nums[i];
     // slice操作也很有必要，这样就具有方向性，在前面的基础上，就不会重复查找了；
     const resArr = twoNum(nums.slice(i + 1), nums[i]);
     // concat很好用，数组合并利器
     res = res.concat(resArr);
     // console.log('res', res);
   }
   return res;
};
```