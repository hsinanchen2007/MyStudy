先计算出能分满的最大次数times；
第times次的第一个数量firstCandies；
分完times次后还剩下多少糖果remainder；
times次之后每次分配还可以再分几个extra；
然后就遍历往结果丢就行

```
var distributeCandies = function(candies, num_people) {
    let n = num_people
    let times = Math.floor(Math.sqrt(n * n * (2 * candies + 0.25)) / (n * n) - 1 / (2 * n))
    let firstCandies = n / 2 * (times * times - times) + times
    let remainder = candies - firstCandies * n - times * 0.5 * (n * n - n)
    let res = [], i = 0
    while (i < num_people) {
        let extra = 1 + times * n + i
        if (remainder <= 0) {
            extra = 0
        } else {
            if (remainder < extra) {
                extra = remainder
            }
            remainder -= extra
        }
        res.push(firstCandies + i * times + extra)
        i++
    }
    return res
};
```
