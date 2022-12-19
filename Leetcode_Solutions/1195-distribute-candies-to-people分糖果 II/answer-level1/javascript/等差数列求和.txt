### 解题思路
可等价为：等差数列求和，再将剩余的数分发到合理的位置。

先根据 S(n) = n(n+1)/2 这一等差数列的求和公式，求解出等差数列的项数 n

再用项数处以人数，得到分发的轮数：round = n / num_people

在 round 轮内，每个人得到的糖果数为 i+1 + (i+1+num_people) + ... + (i+1+(round-1)*num_people) = (2(i+1)+(round-1)num_people)round/2

此时，还剩下 n - num_people*round 人处在等差数列中，依次加上 i+1+round*num_people

最后，还剩下 candies - n(n+1)/2 个糖果，全部分给下一个人。


### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
    const n = Math.floor((Math.sqrt(8 * candies + 1) - 1) / 2);
    const round = Math.floor(n / num_people), result = new Array();
    for (let i = 0; i < num_people; ++i) {
        result.push((2 * (i + 1) + (round - 1) * num_people) * round / 2);
    }
    const restPeople = n - round * num_people;
    for (i = 0; i < restPeople; ++i) {
        result[i] += (i + 1 + round * num_people);
    }
    const remainingCandies = candies - (n * (n + 1)) / 2;
    result[restPeople] += remainingCandies;
    return result;
};
```

### 复杂度分析
- 时间复杂度 O(num_people)
- 空间复杂度 O(num_people)