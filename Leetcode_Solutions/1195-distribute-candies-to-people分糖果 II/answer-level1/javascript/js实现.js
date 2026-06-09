
```
//解法1：
var distributeCandies = function (candies, num_people) {
    let ans = new Array(num_people).fill(0);

    let curr = 1,
        currIndex = 0;
    while (candies > 0) {
        if (candies <= curr) {
            ans[currIndex] += candies;
        } else {
            ans[currIndex] += curr;
        }
        //剩余糖
        candies -= curr;
        curr++;
        currIndex = currIndex === num_people - 1 ? 0 : currIndex + 1;
    }

    return ans;
}; 

//求和公式解法2
var distributeCandies = function (candies, num_people) {
    let n = num_people 
    let p = Math.floor((2 * candies + 0.25) ** 0.5 - 0.5) //获得完整🍬的人数p
    let r = Math.floor(candies - (p + 1) * p * 0.5) //剩余🍬数量r
    let res = new Array(n).fill(0)
    let rows = Math.floor(p / n) //完整的分发回合数
    let cols = p % n // 将剩余的糖果分发给第 p % N 个后面的一个人。
    for (let i = 0; i < n; i++) {
        res[i] = (i + 1) * rows + Math.floor(rows * (rows - 1) * 0.5) * n //complete rows
        if (i < cols) res[i] += i + 1 + rows * n //cols in the last row
    }
    res[cols] += r //remaining 🍬
    return res
```