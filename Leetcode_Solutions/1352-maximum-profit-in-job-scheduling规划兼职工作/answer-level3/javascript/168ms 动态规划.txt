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
        jobs.push([startTime[i],endTime[i],profit[i]]);
    }
    jobs.sort(([s1],[s2]) => s1-s2 );// 按照startTime排序

    // 动态规划
    const dp = [];// 按顺序记录包含jobs[i]的最大收益
    let res = 0;// 记录最大收益
    let pos = 0;// 还没延续到下一个工作的最小位置
    let temp = 0;// jobs[i]startTime之前的最大收益
    for(let i=0; i<jobs.length; i+=1){
        for(let j=pos; j<i; j+=1){
            if(jobs[i][0] >= jobs[j][1]){
                // 如果出现j不等于pos的情况，j必然大于pos，
                // 说明此前有一个工作没延续过，pos停止移动
                if (j === pos) { pos += 1; }
                temp = Math.max(temp, dp[j]);
            }
        }
        dp.push(temp+jobs[i][2]);// 记录包含jobs[i]的最大收益
        res = Math.max(dp[i], res);
    }
    return res;
};
```