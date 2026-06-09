### 解题思路
看代码

### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
    const result = new Array(num_people).fill(0);
    let i = 0 ;
    let candyNums = 1 ;
    while(candies != 0){
        // 选择最小的糖果
        let currentCandy = Math.min(candies,candyNums)
        /**
         * i = 0
         * num_people = 4
         * 模是： 0
         * 目的是：使下标位置处于是0-3，如果i=4，它又回到原点也就是0，符合题意
         */
        result[i % num_people] = result[i % num_people]  + currentCandy ;
        //糖果总数量减去已经分配的数量
        candies = candies - currentCandy;
        //移动下一个下标
        i++;
        //记录糖果数量+1
        candyNums++
    }

    return result;
};
```