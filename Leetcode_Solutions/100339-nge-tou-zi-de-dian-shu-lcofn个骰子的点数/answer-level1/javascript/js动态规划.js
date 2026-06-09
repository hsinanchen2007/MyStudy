### 解题思路
dp[i]存储的是丢第 i 个后每个点数出现的概率

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var twoSum = function(n) {
    let dp=[1];
    let cnt=1;
    while(cnt <= n){
        let tem=[];
        for(let i = cnt-1; i < dp.length; i ++){
            for(let j=1;j<=6;j++){
                if(tem[i+j]==undefined){
                    tem[i+j] = dp[i]/6;
                }
                else{
                    tem[i+j] += dp[i]/6;
                }
            }
        }
        dp=tem;
        cnt++
    }
    return dp.slice(cnt-1);
};
```