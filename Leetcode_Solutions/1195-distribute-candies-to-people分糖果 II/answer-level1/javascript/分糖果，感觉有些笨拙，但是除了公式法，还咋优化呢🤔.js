```
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
    let res = Array(num_people).fill(0);
    let i = 0;
    let start = 1;
    while (candies) {
        if (candies > start) {   // 每次发糖果要估计本次能不能发这么多，有剩余的才能发
            res[i] += start++;
        } else {
            res[i] += candies;   // 发完了
            break;
        }
        candies -= start - 1;   // 减去刚发的糖果
        i++;
        if (i === num_people) {
            i -= num_people;
        }
    }
    return res;
};
```
