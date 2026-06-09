
### 说在前头：整体思路跟id叫王德福的大佬差不多，只不过没有那么多的比喻和修饰。也整理出来给自己备忘下。

看到这一题，一般的第一反应都是暴力法，三层循环嵌套，二话不说就是玩命给他干出来。

```js
  let nums =  [-1, 0, 1, 2, -1, -4];
  var threeSum = function(nums) {
    let arr = [];
    for(let i = 0; i < nums.length-1;i++){
      for(let j = i+1;j<nums.length;j++){
        for(let m = j+1;m<nums.length;m++){
          if(nums[i]+nums[j]+nums[m] === 0){
            arr.push([nums[i],nums[j],nums[m]])
          }
        }
      }
    }
    return arr;
  };
  
  console.log(threeSum(nums));
```

但是呢，这个方法虽然简单粗暴，但是存在着很大的问题，第一点就是当数据量特别大的时候，会导致超时。第二点就是存在着重复的问题，得出来的结果需要去重。第三点，时间复杂度O(n^3)。

所以呢，必须要找一个更简单的方法。

### 双指针

首先把这条题简化成在一个数组中寻找两个数字和为某个值的所有可能。那么大家第一时间也会用暴力法来做，如下：

```js
let nums =  [-1, 0, 1, 2, -1, -4];
  var twoSum = function (nums, sum) {
    let arr = [];
    for (let i = 0; i < nums.length - 1; i++) {
      for (let j = i + 1; j < nums.length; j++) {
        if (nums[i]+nums[j] === sum) {
          arr.push([nums[i], nums[j]])
        }
      }
    }
    return arr;
  };
  console.log(twoSum(nums,1));//[[-1,2],[0,1],[2,-1]]
```

这里就会出现重复的问题，那么我们就可以结合前一次我们学习的双指针的方法来算这一题。在数组首尾放上一个指针，进行相加，然后与结果比较，移动相应的指针。如下：

```js
let nums =  [-1, 0, 1, 2, -1, -4];
  var twoSum = function (nums, sum) {
    let arr = [];
    let left = 0,right = nums.length-1;
    while(left < right){
      if(nums[left]+nums[right]>sum){
        nums[left]>nums[right] ? left++ : right--;
      }else if(nums[left]+nums[right]<sum){
        nums[left]<nums[right] ? left++ : right--;
      }else{
        arr.push([nums[left],nums[right]]);
        nums[left]<nums[right] ? left++ : right--;
      }
    }
    return arr;
  };
  console.log(twoSum(nums,1));//[[-1,2],[0,1]]
```

这种情况就算是基本完成了，不过这里面会有一个重复比较的问题，只要存在相同的值，那么就会有这个问题。解决办法呢就是在最开始就将数组排序，从小到大排列，在比较完一次之后，移动指针的时候进行一个判断，如果移动完之后的值跟之前的值是一样的，那么继续移动指针，直到不能移动为止。数组从小到大排序之后，比较起来也更好判断移动哪根指针;

```js
  let nums =  [-1, 0, 1, 2, -1, -4];
  var twoSum = function (nums, sum) {
    nums = nums.sort((a,b)=>{return a-b});
    console.log(nums);//[-4, -1, -1, 0, 1, 2]
    let arr = [];
    let left = 0,right = nums.length-1;
    while(left < right){
      if(nums[left]+nums[right]>sum){
        //大于和值的时候，右边right值为大的数，移动一格，寻找更小的数
        do{--right}while(nums[right]===nums[right+1])
      }else if(nums[left]+nums[right] < sum){
        //小于和值的时候，左边left值为小的数，移动一格寻找更大的数
        do{++left}while(nums[left]===nums[left-1]);
      }else{
        //等于和值的时候，左右都移动一格，省去重复的值
        arr.push([nums[left],nums[right]]);
        do{--right}while(nums[right]===nums[right+1]);
        do{++left}while(nums[left]===nums[left-1])
      }
    }
    return arr;
  };
  console.log(twoSum(nums,1));//[[-1,2],[0,1]]
```

就这样，数组中两数和为某个值的问题就迎刃而解了。那么我们现在是三个值的和，其实这个反而没有那么复杂。

对数组进行一次循环，每个值为`nums[i]`,然后在剩下的值里面寻找和为`0-nums[i]`的所有可能。同时为了防止重复操作，在循环的时候，前后值相等时候，直接跳过。

而且在最外层循环的时候，因为数组已经从小到大排序过了，所以当循环到大于0的值的时候，直接进行下一次循环。最终的代码如下：

```js
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    nums = nums.sort((a,b)=>{return a-b});
    let arr = [];
    for(let i = 0; i < nums.length;i++){
      if(nums[i]>0 || nums[i] === nums[i-1])continue;
      let sum = 0 - nums[i];
      let left = i+1,right = nums.length-1;
      while(left < right){
       if(nums[left]+nums[right]>sum){
          //大于和值的时候，右边right值为大的数，移动一格，寻找更小的数
          do{--right}while(nums[right]===nums[right+1])
        }else if(nums[left]+nums[right] < sum){
          //小于和值的时候，左边left值为小的数，移动一格寻找更大的数
          do{++left}while(nums[left]===nums[left-1]);
        }else{
          // console.log(nums[i], nums[left], nums[right]);
          //等于和值的时候，左右都移动一格，省去重复的值
          arr.push([nums[i],nums[left],nums[right]]);
          do{--right}while(nums[right]===nums[right+1]);
          do{++left}while(nums[left]===nums[left-1])
        }
      }
    }
    return arr;
  };
```



执行结果：

执行用时 :192 ms, 在所有 JavaScript 提交中击败了95.77%的用户

内存消耗 :46.3 MB, 在所有 JavaScript 提交中击败了86.32%的用户