```
var findContinuousSequence = function(target) {
    if(target < 2) return [];
    const res = [];
    const len = Math.ceil(target / 3) + 1;
    const preSum = [0];
    const continueArr = [];
    for(let i = 1; i <= len; i++) {
        preSum[i] = preSum[i - 1] + i;
        continueArr[i] = i;
        for(let j = 0; j < i - 2; j++) {
            if(preSum[i] - preSum[j] === target) res.push(continueArr.slice(j + 1, i + 1));
        }
    }
    if(target % 2) res.push([parseInt(target / 2, 10), parseInt(target / 2, 10) + 1]);
    return res;
};
```
