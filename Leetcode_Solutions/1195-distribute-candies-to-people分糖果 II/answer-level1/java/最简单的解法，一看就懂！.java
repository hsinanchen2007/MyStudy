# 分析思路：


1. 初始时，所有人手中糖果数量是0
2. i 是循环  j 是 每次循环时，当前应该分发的糖果数量
3. 发糖果之前，先判断当前手中糖果是否够发
4. 更新当前小孩手中的糖果数量 = 之前手中的数量 + 当前应发的糖果数量j
5. 计算剩下还有多少糖果
6. 如果糖果不够，就将剩下的糖果全部给当前小孩，然后结束循环！
7. 当超出范围之后，重新更新i到初始位置



```
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function (candies, num_people) {
    let ans = new Array(num_people).fill(0) // 初始时，所有人手中糖果数量是0
    let i = 0, j = 1   // i 是循环  j 是 每次循环时，当前应该分发的糖果数量
    while (i < num_people) {
        if (j <= candies) { // 发糖果之前，先判断当前手中糖果是否够发
            ans[i] = ans[i] + j  // 更新当前小孩手中的糖果数量 = 之前手中的数量 + 当前应发的糖果数量j
            candies = candies - j   // 计算剩下还有多少糖果
        } else {  // 如果糖果不够，就将剩下的糖果全部给当前小孩，然后结束循环！
            ans[i] = ans[i] + candies
            break
        }
        i++
        j++
        if (i === num_people) {  // 当超出范围之后，重新更新i到初始位置
            i = 0
        }
    }
    return ans
};
```
