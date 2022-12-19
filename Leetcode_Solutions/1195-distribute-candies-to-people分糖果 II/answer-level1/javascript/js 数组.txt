### 解题思路
线性思维
定义一个数组，数组长度n, 顺序给数组的值 +糖果数


### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
    let array = new Array(num_people).fill(0);

    let i = 0;
    let num = 1;
    while(candies > 0) {
        if(num > candies) {
            num = candies;
        }
        array[i] += num;
        candies -= num;

        num += 1;
        i = ++i % num_people;
    }

    return array;
    
};

```