### 解题思路
1.状态
    二进制，一个数的二倍只是左移一位，１的数量不变
    一个奇数的　n 二进制中包含的１的数量，就比ｎ－１多一个，　
    一个偶数　ｎ　二进制中包含的１的数量，和ｎ／２一样多． 
 2. 转移方程
```
        if(i % 2 == 1){
            dp[i] = dp[i-1] + 1;
        }else{
            dp[i] = dp[i/2];
        }
```
3. 初始值和边界
```
  　dp[0] = 0; 
```
4. 计算顺序
 　从小到大
### 代码

```javascript
/**
 * @param {number} num
 * @return {number[]}
 */
var countBits = function(num) {
    let dp = [];
    dp[0] = 0;
    for(let i = 1; i<=num; i++){
        if(i % 2 == 1){
            dp[i] = dp[i-1] + 1;
        }else{
            dp[i] = dp[i/2];
        }
    }
    return dp; 
};
```