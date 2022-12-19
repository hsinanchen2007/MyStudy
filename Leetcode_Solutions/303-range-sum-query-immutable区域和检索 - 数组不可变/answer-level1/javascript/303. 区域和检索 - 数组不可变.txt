# 暴力法
直接挂起数组，每次检索时求和
```
var NumArray = function(nums) {
    this.nums = nums;
};

/** 
 * @param {number} i 
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
    let sum = 0;
    for(let k  = i;k<=j;k++){
        sum += this.nums[k];
    }
    return sum;
};
```
# 尝试二维DP
其实也是暴力法，只不过是在创建该对象时将所有结果穷举了出来，
```
var NumArray = function(nums) {
    let len = nums.length;
    let dp = Array.from({length:len},x=>Array.from({length:len}, y=>0));
    for(let i = 0;i<len;i++){
        for(let j = i;j<len;j++){
            if(i == j){
               dp[i][j] = nums[i];
            }else{
               dp[i][j] = dp[i][j-1] + nums[j];
            }
        }
    }
    console.log(dp)
    this.result = dp;
};

/** 
 * @param {number} i 
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
    return this.result[i][j];
};
```
# DP
DP结果数组与输出结果的关系是差值关系，想透这点就没有问题了
```

var NumArray = function(nums) {
    let dp = [0];
    for(let i = 0,len = nums.length;i<len;i++){
        dp.push(dp[i]+nums[i]);
    }
    this.re = dp;
};

/** 
 * @param {number} i 
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
    let re = this.re;
    return re[j+1]-re[i];
};
```

