// #### 解法一：内置函数 + 正则
// + [191. 位1的个数-解法三](https://leetcode-cn.com/problems/number-of-1-bits/solution/191-wei-1de-ge-shu-by-alexer-660/)
// ```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    let result = [];
    let n = 0;
    while(n <= num){
        result.push((n.toString(2).match(/1/g) || []).length)
        n++;
    }
    return result;
};
// ```
// #### 解法二：位操作
// + [191. 位1的个数-解法二](https://leetcode-cn.com/problems/number-of-1-bits/solution/191-wei-1de-ge-shu-by-alexer-660/)
// ```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    let result = [0];
    let n = 1;
    while(n <= num){
        let count = 0;
        let tmpN = n;
        while(tmpN != 0){
            count++;
            tmpN &= (tmpN-1)
        }
        result.push(count);
        n++;
    }
    return result;
};
// ```
// #### 解法三：模拟十转二进制、取模
// + [191. 位1的个数-解法四](https://leetcode-cn.com/problems/number-of-1-bits/solution/191-wei-1de-ge-shu-by-alexer-660/)
// ```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    let result = [0];
    let n = 1;
    while(n <= num){
        let count = 0;
        let tmpN = n;
        while(tmpN){
            // tmpN % 2 == 1
            if(tmpN & 1 == 1){
                count++;
            }
            tmpN >>>= 1;
        }
        n++;
        result.push(count);
    }
    return result;
};
// ```
// #### 解法四：奇偶 + 位操作
// + 示例
//   + **0 => 0**
//   + 1 => 1
//   + **2 => 10**
//   + 3 => 11
//   + **4 => 100**
//   + 5 => 101
//   + **6 => 110**
//   + 7 => 111
//   + **8 => 1000**
// + 归纳
//   + 设 **dp(n)** 为数字n二进制中1的个数
//   + n为**奇数**
//     + dp(n) = dp(n-1) + 1
//   + n为**偶数**
//     + dp(n) = dp(n/2)
// + 初始化
//   + result = [0]
// ```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    let result = [0];
    let n = 1;
    while(n <= num){
        let count = 0;
        if(n & 1 ==1){
            result[n] = result[n-1]+1;
        }else{
            result[n] = result[n>>1]
        }
        n++;
    }
    return result;
};
// ```
// #### 解法五：循环和位移动
// + [191. 位1的个数-解法一](https://leetcode-cn.com/problems/number-of-1-bits/solution/191-wei-1de-ge-shu-by-alexer-660/)
// ```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    let result = [0];
    let n = 1;
    while(n <= num){
        let count = 0;
        let mask = 1;
        for(let i = 0;i < 32;i++){
            if((n & mask) != 0){
                count++;
            }
            mask <<= 1;
        }
        n++;
        result.push(count);
    }
    return result;
};
// ```
// #### 解法六：解法三 + 解法四  = 升华版
// + 十进制转二进制
//   + ![截屏2019-11-26下午4.42.43.png](https://pic.leetcode-cn.com/75cb47dd45b7a1b9ecea3601c1df8be97ec3ac64ef6934af88c9d4dc93242746-%E6%88%AA%E5%B1%8F2019-11-26%E4%B8%8B%E5%8D%884.42.43.png)
//   + 由图可知，取模时，遇到偶数余数为0
//     + 结合解法四：结果要加上漏掉的偶数的个数1
// + 状态转移方程
//   + **dp(n) = dp(n/2) + n%2**
//   + 等价于**dp(n) = dp(n>>1) + (n&1)**
// ```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    let result = [0];
    let n = 1;
    while(n <= num){
        let tmpN = n;
        result.push(result[tmpN>>1] + (tmpN&1));
        n++;
    }
    return result;
};
// ```
// #### 解法七：参考解法
// ```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    let dp = [0];
    let n = 1;
    while(n <= num){
        dp[n] = dp[n - (Math.pow(2, Math.floor(Math.log2(n))))] + 1;
        n++;
    }
    return dp;
};
// ```
// #### 解法八：解法二 + 解法四 = 升级版
// + n & (n-1) 
//   + 清零最低位的1
// + dp：
//   + **4 => 100**
//   + 5 => 101
//   + **6 => 110**
//   + 7 => 111
//     + dp[7] = dp[6] + 1
//       + 7 & 6 == 6
//     + dp[6] = dp[4] + 1
//       + 6 & 5 == 4
// ```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    let dp = [0];
    let n = 1;
    while(n <= num){
        dp[n] = dp[(n & (n-1))] + 1;
        n++;
    }
    return dp;
};
// ```
// #### 解法N：大家还有啥好的解法欢迎来砸🥰🥰🥰