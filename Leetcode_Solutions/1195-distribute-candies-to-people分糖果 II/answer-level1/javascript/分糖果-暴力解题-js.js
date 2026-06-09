直接模拟分糖果的过程
```
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
    let ans =new Array(num_people).fill(0);
    let pos = 0;
    let candyNum = 1;
    while (candies > 0){
        const currentCandy = Math.min(candies,candyNum);
        ans[pos % num_people ] += currentCandy ;
        candies -= currentCandy;
        pos ++;
        candyNum ++;
    }
    return ans;
};
```
