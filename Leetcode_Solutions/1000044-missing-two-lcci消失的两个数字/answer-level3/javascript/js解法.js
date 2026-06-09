```
// 只想到了空间和时间都是O(n)的解法
let missingTwo = (nums) => {
    let oL = nums.length + 2;
    let hash = {};
    for (let i = 1; i <= oL; i++){
        hash[nums[i - 1]] = true;
        if(hash[i] === true)continue;
        hash[i] = false;
    }
    let res = [];
    for(let k in hash){
        if(hash[k] === false){
            res.push(k / 1);
        }
    }
    return res;
}
```
前端算法库：https://github.com/cunzaizhuyi/js-leetcode  
这里记录了我刷过的近500道LeetCode的题解，
希望对前端同行找工作面试、修炼算法内功有帮助。
前端算法交流群：621067993
