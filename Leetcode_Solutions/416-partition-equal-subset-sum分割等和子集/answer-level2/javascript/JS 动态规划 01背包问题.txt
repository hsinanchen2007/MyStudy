### 解题思路
  典型的背包问题
  把题目转换为，存在一个子数组，和为 sums/2;
  之后的就是正常的 01背包问题
方法一 
使用数组实现
        0 < j < dp[i-1].length
        dp[i][j + nums[i]] = true;
        dp[i][j] = true;
    画一个 表格就出来了
    这道题 只用到了了 dp[i-1] 所以也可以把 二维数组转换成一维数组，在JS中也可以转换为 对象存储。
 方法二 
    思想是一样的，就是这个方法利用JS的动态特性，节省空间，复杂度是一样的，但是因为访问对象属性没有访问数组快，所以速度反而更慢了，适用于限值空间的题目
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {
    let result = nums.reduce((pre,cur) => pre + cur);
    let aver = result / 2;
    let dp = [];
    let i,j;
    for(i=0; i<nums.length;i++){
        dp[i] = [];
    }
    dp[0][nums[0]] = true;
    dp[0][0] = true; 
    for(i = 1;i<nums.length; i++){
        for(j=0; j<dp[i-1].length; j++){
            if(dp[i-1][j]){
                dp[i][j + nums[i]] = true;
                dp[i][j] = true;
            }
            if (dp[i][aver]){
                return true;
            }
        }
    }
    return false;
};

console.log(canPartition([1, 2, 3, 5]))

/**
 * 方法二  
 */
var canPartition = function(nums) {
    let result = nums.reduce((pre,cur) => pre + cur);
    let aver = result / 2;
    let i;
    let dpLast = {};
    dpLast = {
        0:true
    };
    dpLast[nums[0]] = true;
    for(i = 1;i<nums.length; i++){
        let dpNow = {};
        for(let key in dpLast){
            dpNow[parseInt(key) + nums[i]] = true; //把第 i 号物品放入
            dpNow[parseInt(key) ] = true; //不把第 i 号物品放入
            if (dpNow[aver]){
                return true;
            }
        }
        dpLast = dpNow;
        dpNow = null;
    }
    return false;
};
```