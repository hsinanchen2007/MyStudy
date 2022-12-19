### 代码

```javascript
/**
 * @param {number[]} startTime
 * @param {number[]} endTime
 * @param {number[]} profit
 * @return {number}
 */
var jobScheduling = function(startTime, endTime, profit) {
    // 构造新数组
    const jobs = [];
    for(let i=0; i<startTime.length; i+=1){
        jobs.push([
            startTime[i],
            endTime[i],
            profit[i]
        ]);
    }
    jobs.sort(([s1,e1],[s2,e2]) => e1 - e2 );// 按照endTime排序

    function search(dp, s){ // 二分查找
        if(dp.length === 1){ return dp[0]; }
        let m = Math.floor(dp.length/2);
        if(dp[m][0]>s){
            return search(dp.slice(0,m),s);
        }else{
            return search(dp.slice(m),s);
        }
    }
    // 动态规划
    const dp = [[0,0]];// 记录每个状态下的最大收益
    for(let i=0; i<jobs.length; i+=1){
        const prev = search(dp, jobs[i][0])[1];// 工作[i]startTime前的最大收益
        //    现在最大收益            过去最大收益
        if( prev + jobs[i][2] > dp[dp.length-1][1]){
            dp.push([jobs[i][1], prev+jobs[i][2]]);
        }
    }
    return dp[dp.length-1][1];
};
```