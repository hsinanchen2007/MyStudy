```
/**
 * @param {number[]} difficulty
 * @param {number[]} profit
 * @param {number[]} worker
 * @return {number}
 */
var maxProfitAssignment = function(difficulty, profit, worker) {
    let ans = 0
    const arr = []
    for(let i = 0; i < difficulty.length;i++)  arr.push([difficulty[i], profit[i]])
    arr.sort((a, b) => a[0] - b[0])
    worker.sort((a, b) => a - b)
    let j = 0
    let best = 0
    for(let i = 0;i < worker.length;i++) {
        while((j <arr.length) && (arr[j][0] <= worker[i])) {
            let temp = arr[j++][1]
            best = best > temp ? best : temp
        }
        ans += best
    }
    return ans
};
```
